#include <iostream>
#include <string>
using namespace std;
// 
// 
// class Calculator {
// public:
// 	virtual int getResult() {
// 		return 0;
// 	};
// 
// 	int num1;
// 	int num2;
// };
// 
// class CalculatorAdd : public Calculator {
// public:
// 	int getResult() {
// 		return num1 + num2;
// 	}
// };
// 
// class CalculatorSubtract : public Calculator {
// public:
// 	int getResult() {
// 		return num1 - num2;
// 	}
// };
// 
// class CalculatorMultiply : public Calculator {
// public:
// 	int getResult() {
// 		return num1 * num2;
// 	}
// };
// 
// class CalculatorDivide : public Calculator {
// 
// 	int getResult() {
// 		return num1 / num2;
// 	};
// };
// 
// 
// 	int main() {
// 		Calculator * cal_ptr = new CalculatorAdd;
// 		cal_ptr->num1 = 10;
// 		cal_ptr->num2 = 20;
// 
// 		cout << "Add = \t" << cal_ptr->getResult() << endl;
// 
// 		delete cal_ptr;
// 		cal_ptr = new CalculatorSubtract;
// 		cal_ptr->num1 = 10;
// 		cal_ptr->num2 = 20;
// 
// 		cout << "Subtract = \t" << cal_ptr->getResult() << endl;
// 
// 		delete cal_ptr;
// 		cal_ptr = new CalculatorMultiply;
// 		cal_ptr->num1 = 10;
// 		cal_ptr->num2 = 20;
// 
// 		cout << "Multiply = \t" << cal_ptr->getResult() << endl;
// 
// 		delete cal_ptr;
// 		cal_ptr = new CalculatorDivide;
// 		cal_ptr->num1 = 100;
// 		cal_ptr->num2 = 20;
// 
// 		cout << "Divide = \t" << cal_ptr->getResult() << endl;
// 
// 
// 	};
