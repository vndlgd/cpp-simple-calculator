#include <iostream>
#include <string>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"

/* This function lacks input validation
 * if you don't enter an int, the program will crash */
int getUserInteger()
{
	int value{};
	std::cout << "Enter integer: ";
	std::cin >> value;
	return value;
}

/* This function lacks input validation
 * if you type in lots of random characters
 * you will get the invalid operation message displayed many times */
char getMathematicalOperation()
{
	char choice{};
	std::cout << "Enter operation +, -, *, / (enter 'q' to quit): ";
	std::cin >> choice;
	while (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != 'q')
	{
		std::cout << "Invalid operation. Please try again: ";
		std::cin >> choice;
	}
	return choice;
}

void startCalculator()
{
	std::cout << "Simple Calculator!\n";
	char choice{getMathematicalOperation()};

	while (choice != 'q')
	{
		int num1{getUserInteger()};
		int num2{getUserInteger()};

		switch (choice)
		{
		case '+':
			std::cout << add(num1, num2) << '\n';
			break;
		case '-':
			std::cout << subtract(num1, num2) << '\n';
			break;
		case '*':
			std::cout << multiply(num1, num2) << '\n';
			break;
		case '/':
			std::cout << divide(num1, num2) << '\n';
			break;
		}

		choice = getMathematicalOperation();
	}

	if (choice == 'q')
	{
		return;
	}
}

int main()
{
	startCalculator();
	std::cout << "Goodbye.\n";

	return 0;
}
