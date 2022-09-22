#include "MyInterpreter.h"

double MyInterpreter::interpret(const std::string& in, OperatorManager& om)
{
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
        if (std::stoi(om.findOperator(operatorSign))) {
            position = std::stoi(om.findOperator(operatorSign));
        }
        else {
            throw "There is no such operator";
        }
    }
    catch (const std::exception&) {

    }

    ss >> num2String;
    try {
        num2 = std::stod(num2String);
    }
    catch (const std::exception&) {

    }


    return om.getOperators().at(position)(num1, num2);
}
