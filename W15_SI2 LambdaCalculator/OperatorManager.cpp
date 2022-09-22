#include "OperatorManager.h"

void OperatorManager::setOperators(ArithmeticOperator newOper)
{
    operators.push_back(newOper);
}

std::vector<ArithmeticOperator>& OperatorManager::getOperators()
{
    return operators;
}

std::string OperatorManager::findOperator(std::string symbol) const
{
    for (size_t i{ 0 }; i <= operators.size();) {
        if (operators[i].getOperatorSymbol() == symbol) {
            return std::to_string(i);
        }
    }

    return "npos";
}
