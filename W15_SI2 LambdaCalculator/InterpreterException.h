#pragma once
#include <stdexcept>
#include <string>

class InterpreterException
	: public std::exception
{


public:
	std::string name;
	std::string errorMessage;
	std::string expression;

	InterpreterException() = default;
	InterpreterException(std::string name, std::string errorMessage)
		:name(name),
		errorMessage(errorMessage){}

	const char* what() noexcept;
};

