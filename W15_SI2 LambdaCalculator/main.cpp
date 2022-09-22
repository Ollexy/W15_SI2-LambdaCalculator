#include <iostream>
#include "ArithmeticOperator.h"
#include "OperatorManager.h"
#include "InterpreterInterface.h"
#include "MyInterpreter.h"
#include <exception>

int main() {
	auto lambdaDodawanie = [](double x, double y) {return x + y; };
	auto lambdaOdejmowanie = [](double x, double y) {return x - y; };
	auto lambdaMnozenie = [](double x, double y) {return x * y; };
	auto lambdaDzielenie = [](double x, double y) {if (y == 0) throw "Error"; return x / y; };

	ArithmeticOperator dodawanie(lambdaDodawanie, "dodawanie", "+", 2);
	ArithmeticOperator odejmowanie(lambdaOdejmowanie, "odejmowanie", "-", 2);
	ArithmeticOperator mnozenie(lambdaMnozenie, "mnozenie", "*", 1);
	ArithmeticOperator dzielenie(lambdaDzielenie, "dzielenie", "/", 1);

	OperatorManager manager;
	manager.setOperators(dodawanie);
	manager.setOperators(odejmowanie);
	manager.setOperators(mnozenie);
	manager.setOperators(dzielenie);

	MyInterpreter operatorInterpreter;
	std::cout << operatorInterpreter.interpret("5 - 2", manager);

	return 0;
}