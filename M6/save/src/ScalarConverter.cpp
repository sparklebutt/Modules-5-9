/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 15:58:25 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "converterUtils.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& convertee) {
	if (convertee.length() == 1 && std::isprint(convertee[0]) && !std::isdigit(convertee[0]))
		convertChar(convertee);
	handleSpecialInput(convertee);
	int	value = establishInput(convertee);
	switch (value)
	{
		case 0:
			convertNum(convertee);
			break;
		case 1:
			convertDouble(convertee);
			break;
		case 2:
			convertFloat(convertee);
	}	
}