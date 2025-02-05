/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 14:13:56 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "converterUtils.hpp"

// note that if you send only * not '*' , programme will assume
// you are sending in all files in directory

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout<<"sent home argc = "<<argc<<"\n";
		return 1;
		
	}
	std::cout<<"start\n";
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception has been caught in main " << e.what() << '\n';
	}
	std::cout<<"end\n";

	return 0;
}