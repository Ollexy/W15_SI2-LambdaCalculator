#include "InterpreterException.h"

const char* InterpreterException::what() noexcept
{
    std::string result = '"' + name + " : " + errorMessage + " : " + expression + '"';

    return result.c_str();
}
