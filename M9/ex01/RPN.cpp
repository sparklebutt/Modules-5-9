/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:47:35 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/05 10:22:00 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <algorithm>
RPN::RPN () {
	std::cout<<" defalut constructor called\n";
}

RPN::RPN(const std::string& expression) {

	initialValidation(expression);
	//	throw std::runtime_error("expression invalid");
	m_expression =  expression;
	std::cout<<"set up constructor called\n";
}

/**
 * @brief stack depth will always  need 
 * 
 * @param input 
 * @return true 
 * @return false 
 */
void RPN::initialValidation(const std::string& input)
{
	if (input.length() == 1)
		throw std::runtime_error("Input has only 1 char \n");
	if (input.empty())
		throw std::runtime_error("Input is empty \n");
	if (input.find_first_not_of(" +-*/0123456789") != std::string::npos)
		throw std::runtime_error("Input has invalid character : only= ('space') and (+-*/) and (0,1,2,3,4,5,6,7,8,9)\n");
	if (input.find_first_not_of(' ') == std::string::npos)
		throw std::runtime_error("Input contains only spaces\n");
	if (input.find_first_of("+-*/") == std::string::npos)
		throw std::runtime_error("Expression does not contain any valid operators\n");
	if (!isdigit(input.front()))
		throw std::runtime_error("First char is not a digit \n");
}

bool RPN::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double RPN::performOperation(const std::string& operation, double operand1, double operand2) {
	if (operation == "+") return operand1 + operand2;
    else if (operation == "-") return operand1 - operand2;
    else if (operation == "*") return operand1 * operand2;
    else if (operation == "/") {
        if (operand2 == 0) throw std::runtime_error("Error: Division by zero");
        return operand1 / operand2;
    }
    throw std::runtime_error("Error: Invalid operator");
}

double RPN::validateNumber(const std::string& num)
{
	double number;
	try {
		number = std::stod(num);
		if (number > 10)
			throw std::runtime_error("Error: Invalid number , numbers above 10 forbidden");
	} catch (const std::invalid_argument&) {
		throw std::runtime_error("Error: Invalid number in the expression");
		}
	return number;	
}
double RPN::evaluate() {
    std::stack<double> stack;
    std::istringstream tokens(m_expression);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0]))
            stack.push(validateNumber(token));
			
        else if (isOperator(token[0])) {
            if (token.size() != 1 || stack.size() < 2)
                throw std::runtime_error("Error: Invalid RPN expression");   
            double operand2 = stack.top(); stack.pop();
            //double operand1 = stack.top(); stack.pop();
            stack.top() = performOperation(token, stack.top(), operand2);
			//stack.push(performOperation(token, operand1, operand2));
        }
		else
            throw std::runtime_error("Error: Unknown :: RPN.cpp line 96");
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: Invalid RPN expression");
    }
    return stack.top();
}
double RPN::calculation()
{
	return evaluate();//result;
}

RPN::~RPN () {std::cout<<"destructor called\n";}
