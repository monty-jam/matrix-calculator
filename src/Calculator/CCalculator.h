#ifndef SEMESTRAL_CCALCULATOR_H
#define SEMESTRAL_CCALCULATOR_H


#include "CEvaluator.h"

class CCalculator {
public:
    CCalculator() = default;
    void run();

private:
    CEvaluator m_Evaluator;

    void readInput();
};


#endif //SEMESTRAL_CCALCULATOR_H
