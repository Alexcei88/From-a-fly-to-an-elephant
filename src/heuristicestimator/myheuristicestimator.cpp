#include "myheuristicestimator.h"

MyHeuristicEstimator::MyHeuristicEstimator(const std::string& endWorld)
    : IHeuristicEstimator(endWorld)
{

}

ulong MyHeuristicEstimator::GetHeuristicEvaluation(const std::string& world) const
{
    ulong H = 0;
    for(int i = 0; i < _endWorldLength; i = i + 2)
    {
        H += ((_endWorld[i] == world[i] && _endWorld[i + 1] == world[i + 1]) ? MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION
                                               : NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION);
    }
    return H;
}

