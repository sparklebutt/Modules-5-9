/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:14 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 15:05:05 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <limits>
#include <cctype>
#include <cmath>
/**
 * @brief since this is a utility class, needs to not be insatiatable , we make
 * the constructor private. Utility classes are classes that are used to preform
 * but are not inherited. If this where a base class for inheritence , we would make
 * it abstract. 
 * 
 * 
 * @note a string representation of a C++ literal in its most common form
 * literallaly means a string will be recieved that will represent what must be converted.
 */
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter (const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter();
	public:
		static void convert(const std::string& convertee);
};