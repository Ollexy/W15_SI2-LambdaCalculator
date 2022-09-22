#include "MyInterpreter.h"


double MyInterpreter::interpret(const std::string& in, OperatorManager& om)
{
    InterpreterException error("asdas", "asdasd");

    int position{};
    double num1{}, num2{};
    
    std::string num1String{ "" }, num2String{ "" };
    std::string operatorName{}, operatorSign{};
    std::stringstream ss(in);

    ss >> num1String;
    try {
        num1 = std::stod(num1String);
    }
    catch (const std::exception&) {

    }

    ss >> operatorSign;
    try {
       auto index = std::find_if(om.getOperators().begin(), om.getOperators().end(), [operatorSign](auto a) mutable {
            return a.getOperatorSymbol() == operatorSign; });

        if (index != om.getOperators().end()) {
            position = std::stoi(om.findOperator(operatorSign));
        }
        else {
            error.expression = operatorSign;
            throw error;
        }
    }
    catch (InterpreterException& error2) {
        error2.what();
    }

    ss >> num2String;
    try {
        num2 = std::stod(num2String);
    }
    catch (const std::exception&) {

    }
    double result{};
    ss >> operatorSign;
    try {
       result = om.getOperators().at(position)(num1, num2);
    }
    catch (const std::exception& message) {
        std::cout << message.what();
    }

    return result;
}
