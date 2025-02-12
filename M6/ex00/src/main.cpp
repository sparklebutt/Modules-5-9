/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/11 16:30:38 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "converterUtils.hpp"

// note that if you send only * not '*' , programme will assume
// you are sending in all files in directory

/*void handlePseudoLiterals(double value) {
    if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "Positive infinity" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "Negative infinity" << std::endl;
    } else if (std::isnan(value)) {
        std::cout << "NaN (Not a Number)" << std::endl;
    } else {
        std::cout << "Regular number: " << value << std::endl;
    */

   /*
	for testing i guess 
    std::string input1 = "1e309";      // Positive infinity
    std::string input2 = "-1e309";     // Negative infinity
    std::string input3 = "invalid";    // NaN
    std::string input4 = "42.0"
   */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout<<"sent home argc = "<<argc<<"\n";
		return 1;
		
	}
	//ScalarConverter steve = ScalarConverter();
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