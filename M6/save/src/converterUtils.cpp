/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:00 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 16:33:05 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converterUtils.hpp"
//#include "ScalarConverter.hpp"

void	handleSpecialInput(std::string convertee)
{
	if (convertee == "-inff" || convertee == "+inff" || convertee == "nanf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: "<< convertee<< std::endl;
		std::cout << "double: " << convertee.substr(0, convertee.length() - 1) << std::endl;
		std::exit(0);
	}
	if (convertee == "-inf" || convertee == "+inf" || convertee == "nan")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: "<< convertee<<"f"<< std::endl;
		std::cout << "double: " << convertee << std::endl;
		std::exit(0);
	}	
}

/**
 * @brief tis is a union , a double can hold a float 
 * 
 * @param value 
 * @param flt 
 */
void	handleDisplayValidation(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::floor(value) == value && value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
	else
		std::cout << "char: non displayable "<< std::endl;
	if (value < -std::numeric_limits<int>::max() || value > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
int		establishInput(std::string convertee)
{
	int dot = 0; int f = 0; char prevChar = '\0'; 
	for (char c : convertee)
	{
		bool signAtStart = ((c == '-' || c == '+') && c == convertee.front());
		bool dotInMiddle = (c == '.' && c != convertee.back() && c != convertee.front()); 
		bool floatValid = (c == 'f' && c == convertee.back() && isdigit(prevChar));		
		dot += dotInMiddle; // bool is 0 or 1, so if true we add a dot.
		f += floatValid; // dont know if i need this 
		prevChar = c;
		if (((!std::isdigit(c)) && !signAtStart && !dotInMiddle && !floatValid) 
		|| (dot > 1 || (floatValid && dot == 0)))
			throw std::runtime_error("not a valid input");	
	}
	if (dot > 0)
		return f > 0 ? 2 : 1;
	return 0;
}
void	convertChar(std::string convertee) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: '" << static_cast<unsigned char>(convertee[0]) << "'" << std::endl;
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
	} catch(const std::exception& e) {
		throw std::runtime_error("integer overflow caught");
	}
	std::cout << std::fixed << std::setprecision(1);
	handleDisplayValidation(integer);
}
void	convertDouble(std::string convertee)
{
	std::cout << "handle double "<< std::endl;

	double dub;
	try	{
		dub = stod(convertee);
	} catch(const std::exception& e) {
		throw std::runtime_error("double overflow ");
	}
	std::cout << std::fixed << std::setprecision(1);
	handleDisplayValidation(dub);
}

void	convertFloat(std::string convertee)
{
	float flt;
	try	{
		flt = stof(convertee);
	} catch(const std::exception& e) {
		throw std::runtime_error("double overflow caught");
	}
	std::cout << std::fixed << std::setprecision(1);
	handleDisplayValidation(flt);
}
