#pragma once
#include <stdexcept>
#include <string>

class InterpreterException
	: public std::exception
{
	std::string name;
	std::string errorMessage;


public:
	InterpreterException() = default;
	//const char* what() noexcept;
};

