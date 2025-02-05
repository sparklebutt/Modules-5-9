/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:45:44 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/05 10:22:26 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stack>
class RPN
{
	private:
		std::string m_expression;
		void initialValidation(const std::string& input);
		bool isOperator(char ch);
		double performOperation(const std::string& operation, double operand1, double operand2);
		double evaluate();
		double validateNumber(const std::string& num);

	public:
		RPN ();
		RPN (const std::string& expression);
		RPN (RPN &other) = delete;
		RPN& operator=(RPN &other) = delete;
		~RPN ();
		double calculation();
};