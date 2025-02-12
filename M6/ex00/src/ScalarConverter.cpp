/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/12 16:29:23 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "converterUtils.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& convertee) {
	// handle if there is more than 1 char by removing length check and convert char can handle 
	// special message 
	if (convertee.length() == 1 && std::isprint(convertee[0]) && !std::isdigit(convertee[0]))
		convertChar(convertee);
	handleSpecialInput(convertee);
	int	value = establishInput(convertee);
	if (value == 2)
		convertFloat(convertee);
	else
		convertNum(convertee);
}