#include <queue>
#include <algorithm>
#include <exception>


#include "flytoelephant.h"
#include "world.h"
#include "heuristicestimator/myheuristicestimator.h"

using namespace std;

FlyToElephant::FlyToElephant(  const string& initWorld
                             , const string& endWorld
                             , const std::vector<std::string>& dictionary)
    : _initWorld(initWorld)
    , _endWorld(endWorld)
{

    const size_t initWorldLength = initWorld.length();

    for(const string& w : dictionary)
    {
        // Так как по заданию в результрующей цепочке длины слов совпадает с длиной исходного слова
        // то сразу же убираем все слова, которые не совпадают с длиной
        if(w.length() == initWorldLength)
        {
            _dictWorld.push_back(w);
        }
    }
}

/**
 * @brief Execute - функция по выполнению мухи в слона
 * @return
 */
const std::vector<std::string> FlyToElephant::Execute()
{    
    // 0. инициализируем список слов, с которым будем работать
    std::copy( _dictWorld.begin(), _dictWorld.end(), std::back_inserter( _curDictWorld ) );

    // 1. начальное слово
    std::shared_ptr<World> startWorld = std::make_shared<World>(_initWorld);
    _curDictWorld.remove(_initWorld);
    std::shared_ptr<World> endWorld = std::make_shared<World>(_endWorld);

    // 2. Инициализируем эвристический анализатор
    std::shared_ptr<IHeuristicEstimator> estimator = std::make_shared<MyHeuristicEstimator>(_endWorld);

    // 3. список всех слов
    std::list<std::shared_ptr<World>> allWorlds;

    // 4. очередь мутаций слов, которые последовательно просматриваем
    queue<std::shared_ptr<World>> queueWorld;
    queueWorld.push(startWorld);

    allWorlds.push_back(startWorld);

    bool findEndWorld = false;

    while(!queueWorld.empty() && !findEndWorld)
    {
        // 5. берем самую приоритетную мутацию на текущий момент
        auto currentWorld = queueWorld.front();
        queueWorld.pop();

        // 6. получаем список доступных мутации от текущего слова(которые отличаются на одну букву)
        auto mutation = GetMutationForWorld(currentWorld.get());

        // 7. сортируем мутации с помощью эвристической анализатора
        std:sort(mutation.begin(), mutation.end(), [&](std::shared_ptr<World> a, std::shared_ptr<World> b) -> bool
        {
            return estimator->GetHeuristicEvaluation(a->GetWorld()) < estimator->GetHeuristicEvaluation(b->GetWorld());
        });

        // 8. добавляем все мутации в очередь(слов находяться в приоритете согласно эвристическому анализатору)
        for(auto& w : mutation)
        {
            // проверяем, что среди мутаций нет того, которое в итоге ищем, если нашли, то прерываем цикл
            if(w->GetWorld() == endWorld->GetWorld())
            {
                // мы нашли наше слово, можно дальше не продолжать поиск
                endWorld = w;
                findEndWorld = true;
                break;
            }

            queueWorld.push(w);
            allWorlds.push_back(w);
        }
    }

    if(!findEndWorld)
    {
        // мы не смогли найти путь до получения слова
        throw std::exception();
    }

    // формируем итоговую последовательность
    std::vector<std::string> result;
    const World* curParentPtr = endWorld.get();
    while(curParentPtr != nullptr)
    {
        result.push_back(curParentPtr->GetWorld());
        curParentPtr = curParentPtr->GetParent();
    }
    allWorlds.clear();

    std::reverse(result.begin(), result.end());
    return result;
}


std::vector<std::shared_ptr<World>> FlyToElephant::GetMutationForWorld(const World* world)
{
    std::vector<std::shared_ptr<World>> result;

    auto i = std::begin(_curDictWorld);
    while (i != std::end(_curDictWorld))
    {
        if(world->IsOneDegreeMutation(*i))
        {
            result.push_back( std::make_shared<World>(*i, world));
            _curDictWorld.erase(i++);
        }
        else
        {
            ++i;
        }
    }
    return result;
}


