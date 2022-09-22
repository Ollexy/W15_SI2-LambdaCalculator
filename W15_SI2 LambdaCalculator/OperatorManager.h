#pragma once
#include <vector>
#include "ArithmeticOperator.h"

class OperatorManager
{
	std::vector<ArithmeticOperator> operators{};

public:
	void setOperators(ArithmeticOperator newOper);
	std::vector<ArithmeticOperator>& getOperators();
	std::string findOperator(std::string name) const;
};

