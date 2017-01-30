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
    int diffCount = 0;
    for(int i = 0; i < _lengthWorld; i = i + 2)
    {
        if(_world[i] != world[i] || _world[i + 1] != world[i + 1])
        {
            ++diffCount;
        }
        if(diffCount > 1)
            return false;
    }
    return diffCount == 1;
}
