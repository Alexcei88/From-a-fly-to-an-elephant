#ifndef FLYTOELEPHANT_H
#define FLYTOELEPHANT_H

#include <string>
#include <vector>
#include <list>
#include <memory>

class World;

/**
 * @brief The FlyToElephant class - класс по реализации конвертации мухи в слона
 * Главная функция Execute()
 * Реализует шаблон проектирования - поиск в ширину с эвристической оценкой для поиска наилучшего выбора для поиска на каждому уровне дерева
 */
class FlyToElephant
{
public:
    FlyToElephant(const std::string& initWorld, const std::string& endWorld, const std::vector<std::string> &dictionary);

    /**
     * @brief Execute - функция по выполнению мухи в слона
     * @return
     */
    const std::vector<std::string> Execute();
private:
    /**
     * @brief _initWorld - начальное слово(муха)
     */
    const std::string _initWorld;

    /**
     * @brief _endWorld - конечное слово(слон)
     */
    const std::string _endWorld;

    /**
     * @brief _dictWorld - словарь всех возможных слов
     */
    std::vector<std::string> _dictWorld;

    /**
     * @brief _curDictWorld - список слов, которые использует текущий алгоритм(служебное поле)
     */
    std::list<std::string> _curDictWorld;

    /**
     * @brief GetMutationForWorld - получение доступного списка мутаций для текущего слова
     * @param world текущее слово
     * @return возрващает массив мутаций
     */
    std::vector<std::shared_ptr<World>> GetMutationForWorld(const World* world);

};

#endif // FLYTOELEPHANT_H
