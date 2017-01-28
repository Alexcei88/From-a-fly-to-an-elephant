#include "world.h"
#include <cmath>


using namespace std;

World::World(const string& world, const World* parent)
    : _world(world)
    , _parent(parent)
    , _lengthWorld(world.length())
{

}

bool World::operator == (const World& world)
{
    return this->_world == world._world;
}

void World::AddMutation(const World* world)
{
    _mutationWorlds.push_back(world);
}

const World* World::GetParent() const
{
    return _parent;
}

const std::string& World::GetWorld() const
{
    return _world;
}

bool World::IsOneDegreeMutation(const string& world) const
{
    const int otherLength = world.length();

    const int diffLength = fabs(_lengthWorld - otherLength);

    // если слова отличаются длиной, то эти слова откидываем, так как согласно заданию, все промежуточные слова должны состоять из одинакового количества букв
    if(diffLength > 0)
        return false;

    int diffCount = 0;
    for(int i = 0; i < otherLength; ++i)
    {
        if(_world[i] != world[i])
        {
            ++diffCount;
        }
        if(diffCount > 1)
            return false;
    }
    return diffCount == 1;
}
