#include "myheuristicestimator.h"

MyHeuristicEstimator::MyHeuristicEstimator(const std::string& endWorld)
    : IHeuristicEstimator(endWorld)
{

}

ulong MyHeuristicEstimator::GetHeuristicEvaluation(const std::string& world) const
{
    const size_t worldLength = world.length();
    const int G = this->_endWorldLength == worldLength ? SAME_LENGTH_EVALUTION
                                                       : NOT_SAME_LENGTH_EVALUTION;

    ulong H = 0;
    if(worldLength == _endWorldLength)
    {
        for(int i = 0; i < _endWorldLength; ++i)
        {
            H += ((_endWorld[i] == world[i]) ? MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION
                                                   : NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION);
        }
    }
    else
    {
        if(worldLength > _endWorldLength)
        {
            H = CalculateEvaluationWithShiftLength(world, _endWorld, _endWorldLength);
        }
        else
        {
            H = CalculateEvaluationWithShiftLength(_endWorld, world, worldLength);
        }
    }
    return G + H;
}

ulong MyHeuristicEstimator::CalculateEvaluationWithShiftLength(const std::string& longerWorld, const std::string& shorterWorld, const size_t shorterLengthWorld) const
{
    ulong hSamePosition = 0;
    for(size_t i = 0; i < shorterLengthWorld; ++i)
    {
        hSamePosition += ((longerWorld[i] == shorterWorld[i]) ? MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION
                                                              : NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION);
    }
    ulong hShiftPosition = 0;
    for(size_t i = 0; i < shorterLengthWorld; ++i)
    {
        hShiftPosition += ((shorterWorld[i] == longerWorld[i + 1]) ? MATCH_SYMBOL_IN_SHIFT_POSITION_EVALUTION
                                                                    : NOT_MATCH_SYMBOL_IN_SHIFT_POSITION_EVALUTION);
    }
    // в итоге берем тот, в котором меньше
    return ( hSamePosition > hShiftPosition ) ? hShiftPosition : hSamePosition;
}

