/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:00 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 12:57:53 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converterUtils.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype> // isdigit, isprint
#include <cmath> // double, float
#include <iomanip> // set percision

/**
 * When input string given is forced as any below in if ("*") we know char and int to be impossible
 * however we can convert the values to float and double, giving the same result, but they are converted.
 */
void	handleSpecialInput(std::string convertee)
{
	if (convertee == "-inff" || convertee == "+inff" || convertee == "nanf"|| 
		convertee == "nan" || convertee == "-inf" || convertee == "+inf" || 
		convertee == "inf" || convertee == "inff")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		float val = stof(convertee);
		double dval = stod(convertee);
		std::cout << "float: "<< val<< "f"<<std::endl;
		std::cout << "double: " << dval << std::endl;
		std::exit(0);
	}
}

/**
 * When all possible conversions run to an overflow, we manualy print inf, 
 * we have reached the end of this codes scope. 
 */
void	printFullOverflow(std::string& convertee)
{
	if (convertee[0] == '-')
	{
		std::cout << "char: non displayable" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;		
	}
	else
	{
		std::cout << "char: non displayable" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;		
	}

}
/**
 * @brief 
 * 
 * If conversion to int succeeds, we check if value is a char in ascii range.
 * setprecision is set to show 1 decimal place.
 * We static_cast<> to float and double as value sent in is already a int. 
 * @param int
 */

void	handleDisplayValidation(int value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::floor(value) == value && value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: non displayable "<< std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

/**
 ** @brief 
 * 
 * If conversion to float succeeds, we check if value is a char in ascii range.
 * setprecision is set to show 1 decimal place.
 * We static_cast<> to float and double as value sent in is already a int. 
 * @param float 
 * static_cast to float before comparing if int min or max to ensure percision,
 * int value maybe rounded down from 2147483647.1, leading to inaccurate statement that
 * value is not int overflow.
 */
void	handleDisplayValidation(float value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::floor(value) == value && value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: non displayable "<< std::endl;
	if (value < static_cast<float>(std::numeric_limits<int>::min())
		|| value > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}


/**
 ** @brief 
 * 
 * If conversion to double succeeds, we check if value is a char in ascii range.
 * setprecision is set to show 1 decimal place.
 * We static_cast<> to int and double as value sent in is already a int. 
 * @param float 
 * static_cast to float before comparing if int min or max to ensure percision,
 * int value maybe rounded down from 2147483647.1, leading to inaccurate statement that
 * value is not int overflow.
 */
void	handleDisplayValidation(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::floor(value) == value && value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: non displayable "<< std::endl;
	if (value < static_cast<float>(std::numeric_limits<int>::min())
		|| value > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}


int		establishInput(std::string convertee)
{
	int dot = 0; int f = 0; char prevChar = '\0'; 
	if (convertee.back() == '.')
		throw std::runtime_error("value can not end in a decimal");
	for (char c : convertee)
	{
		bool signAtStart = ((c == '-' || c == '+') && c == convertee.front());
		bool dotInMiddle = (c == '.' && c != convertee.back() && c != convertee.front()); 
		bool floatValid = (c == 'f' && c == convertee.back() && isdigit(prevChar));		
		dot += dotInMiddle;
		f += floatValid;
		prevChar = c;
		if (dot > 1)
			throw std::runtime_error("only 1 decimal allowed");
		if (floatValid && dot == 0)	
			throw std::runtime_error("float must have a decimal");
		if ((!std::isdigit(c)) && !signAtStart && !dotInMiddle && !floatValid)
			throw std::runtime_error("not a valid input, only 1 char at a time or a numeric value");
	}
	if (dot > 0)
		return f > 0 ? 2 : 1;
	return 0;
}

void	convertChar(std::string convertee) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: '" << static_cast<char>(convertee[0]) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(convertee[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(convertee[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(convertee[0]) << std::endl;
	std::exit(0);
}

void	convertNum(std::string convertee)
{
	int integer = 0;
	try	{
		integer = stoi(convertee);
		std::cout << std::fixed << std::setprecision(1);
		handleDisplayValidation(integer);
	} catch(const std::exception& e) {
		convertFloat(convertee);
	}
}

void	convertDouble(std::string convertee)
{
	double dub = 0;
	try	{
		dub = stod(convertee);
		std::cout << std::fixed << std::setprecision(1);
		handleDisplayValidation(dub);		
	} 
	catch(const std::exception& e) {
		printFullOverflow(convertee);
	}
}

void	convertFloat(std::string convertee)
{
	float flt = 0;
	try	{
		flt = stof(convertee);
		std::cout << std::fixed << std::setprecision(1);
		handleDisplayValidation(flt);
	} catch(const std::exception& e) {
		convertDouble(convertee);
	}

}
