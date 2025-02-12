/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:07:00 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/12 16:22:17 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converterUtils.hpp"
//#include "ScalarConverter.hpp"

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
 * @brief tis is a union , a double can hold a float 
 * 
 * An oveflow of a float or double does not always mean an overflow inf int
 * @param value 
 * @param flt 
 */

void	handleDisplayValidation(int value)
{
	// to get 1 decimal point
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
 * static_cast to float before comparing if int min or max ensure percision,
 * int value maybe rounded too 2147483647, conversion to float allows for 0.1 to be overflow.
 */
void	handleDisplayValidation(float value)
{
	// to get 1 decimal point
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
	for (char c : convertee)
	{
		bool signAtStart = ((c == '-' || c == '+') && c == convertee.front());
		bool dotInMiddle = (c == '.' && c != convertee.back() && c != convertee.front()); 
		bool floatValid = (c == 'f' && c == convertee.back() && isdigit(prevChar));		
		dot += dotInMiddle; // bool is 0 or 1, so if true we add a dot.
		f += floatValid; // dont know if i need this 
		prevChar = c;
		if (((!std::isdigit(c)) && !signAtStart && !dotInMiddle && !floatValid) 
		|| (dot > 1 || (floatValid && dot == 0))) // could have a better error message fucntion here 
			throw std::runtime_error("not a valid input");	
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
