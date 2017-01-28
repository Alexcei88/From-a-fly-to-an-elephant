#ifndef IHEURISTICESTIMATOR_H
#define IHEURISTICESTIMATOR_H

#include <string>
#include <limits>

/**
 * @brief The IHeuristicEstimator class - абстрактный класс эвристического анализатора для
 * выбора наиболее близкого слова к конечному слову.
 * Значение конечного слово передается через параметр конструктора
 */
class IHeuristicEstimator
{
public:
    /**
     * @brief IHeuristicEstimator - конструктора
     * @param endWorld - конечное слово(слон)
     */
    IHeuristicEstimator(const std::string& endWorld);

    /**
     * @brief GetHeuristicEvaluation - получиь эвристической оценку. Чем ниже число, тем более слово близко к конечному слову
     * @param world - текущее слово
     * @return число, чем меньше, тем данное слово более близко к конечному слову
     */
    virtual ulong GetHeuristicEvaluation(const std::string& world) const = 0;

protected:

    /**
     * @brief MAX_EVALUATION_VALUE - максимальная оценка
     */
    static const ulong MAX_EVALUATION_VALUE = std::numeric_limits<ulong>::max();

    /**
     * @brief MIN_EVALUATION_VALUE - минимальная оценка
     */
    static const ulong MIN_EVALUATION_VALUE = 0;

    /**
     * @brief _endWorld - конечное слово для оценки эвристики
     */
    const std::string _endWorld;

    /**
     * @brief _endWorldLength - длина конечного слова
     */
    const size_t _endWorldLength;
};

#endif // IHEURISTICESTIMATOR_H
