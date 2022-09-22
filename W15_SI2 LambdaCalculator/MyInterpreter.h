#pragma once
#include "InterpreterInterface.h"
#include <sstream>

class MyInterpreter
	: public InterpreterInterface
{
public:
	virtual double interpret(const std::string& in, OperatorManager& om) override;
};

