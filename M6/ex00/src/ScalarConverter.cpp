/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 12:22:38 by araveala         ###   ########.fr       */
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
	if (value == 2)
		convertFloat(convertee);
	else if (value == 1)
		convertDouble(convertee);
	else
		convertNum(convertee);
}