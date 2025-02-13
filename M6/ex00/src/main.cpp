/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 13:33:55 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream> //
#include <exception> //

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout<<"1 argument (only) required = "<<argc<<"\n";
		return 1;
		
	}
	//ScalarConverter steve = ScalarConverter();
	try
	{
		ScalarConverter::convert(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << "Exception has been caught in main " << e.what() << '\n';
	}
	return 0;
}