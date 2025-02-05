/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:35:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/17 16:33:25 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void testinitilization2()
{
 	std::cout<< GREEN "-----START OF AForm INITLIZATION FAIL TESTING-------" RESET <<std::endl;
	try	{	
		AForm A2 = AForm("A2 grade to sign too low", 0, 1);
	}	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {	
		AForm A2 = AForm("A2 grade to execute too low", 1, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}		
	try {	
		AForm A2 = AForm("A2 grade to sign too high", 151, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{	
		AForm A2 = AForm("A2 grade to execute too high", 1, 151);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}	
	std::cout<< GREEN "-----END OF AForm INITLIZATION FAIL TESTING-------" RESET <<std::endl;
}
void testUnsignable()
{
	std::cout<< GREEN "-----START OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;	
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low", 150);
		AForm A2 = AForm("A2", 1, 1);
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
	} catch(const std::exception& e) {
	std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low", 6);
		AForm A2 = AForm("A2", 5, 1);
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;
}
void showWorking2()
{
	std::cout<< GREEN "-----SART OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		AForm A2 = AForm("A2", 1, 1);
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		std::cout<<A2<<std::endl;

	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}	
	std::cout<< GREEN "-----END OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
}
void runAtests()
{
	try {
		testinitilization2();	
		testUnsignable();
		showWorking2();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in runAtests "<<e.what() << '\n';
	}
}