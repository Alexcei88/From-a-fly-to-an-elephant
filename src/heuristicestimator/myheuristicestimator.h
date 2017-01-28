#ifndef MYHEURISTICESTIMATOR_H
#define MYHEURISTICESTIMATOR_H

#include "iheuristicestimator.h"

/**
 * @brief The MyHeuristicEstimator class - моя реализация эвристического анализатора
 * Эвристическая функция F = G + H
 * G - длина слов
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
    static const int NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION = 5;

    /**
     * @brief SAME_LENGTH_EVALUTION - слова имеют одинаковую длину
     */
    static const int SAME_LENGTH_EVALUTION = 0;

    /**
     * @brief NOT_SAME_LENGTH_EVALUTION - слова имеют одинаковую длину
     */
    static const int NOT_SAME_LENGTH_EVALUTION = 1;

    /**
     * @brief MATCH_SYMBOL_IN_SAME_POSITION - эвристическое значение, когда символы совпадают со сдвигом на одну позицию
     * при не равной длине проверяющих слов(длина отличается ровно на 1 символ)
     */
    static const int MATCH_SYMBOL_IN_SHIFT_POSITION_EVALUTION = 1;

    /**
     * @brief NOT_MATCH_SYMBOL_IN_SAME_POSITION_EVALUTION - эвристическое значение, когда символы не совпадают со сдвигом на одну позицию
     * при не равной длине проверяющих слов(длина отличается ровно на 1 символ)
     */
    static const int NOT_MATCH_SYMBOL_IN_SHIFT_POSITION_EVALUTION = 6;

    /**
     * @brief CalculateEvaluationWithShiftLenght - вычисление эвристической оценки для слов с различной длиной
     * @param longerWorld - длинное слово
     * @param shorterWorld - короткое слово
     * @return
     */
    ulong CalculateEvaluationWithShiftLength(const std::string& longerWorld
                                           , const std::string& shorterWorld
                                           , const size_t shorterLengthWorld) const;


};

#endif // MYHEURISTICESTIMATOR_H
