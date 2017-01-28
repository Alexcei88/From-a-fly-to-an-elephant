#ifndef MYHEURISTICESTIMATOR_H
#define MYHEURISTICESTIMATOR_H

#include "iheuristicestimator.h"

/**
 * @brief The MyHeuristicEstimator class - моя реализация эвристического анализатора
 * Эвристическая функция F = H
 * H - соответствие слов на позициях
 */
class MyHeuristicEstimator
        : public IHeuristicEstimator
{
public:
    MyHeuristicEstimator(const std::string& endWorld);

    /**
     * @brief GetHeuristicEvaluation - получиь эвристической оценку. Чем ниже число, тем более слово близко к конечному слову
     * @param world - текущее слово
     * @return число, чем меньше, тем данное слово более близко к конечному слову
     */
    ulong GetHeuristicEvaluation(const std::string &world) const;

private:
    /**
     * @brief MATCH_SYMBOL_IN_SAME_POSITION - эвристическое значение, когда символы находятся на одной позиции
     */
    static const int MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION = 0;

    /**
     * @brief NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION - эвристическое значение, когда символы находятся на одной позиции
     */
    static const int NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION = 1;

};

#endif // MYHEURISTICESTIMATOR_H
