/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:35:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 11:17:47 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

/**
 * showing that form behaves like bureaucrat and throws exception when grade is out of bounds
 * during instantiation.
 */
void testinitilization2()
{
 	std::cout<< GREEN "-----START OF AForm INITLIZATION FAIL TESTING-------" RESET <<std::endl;
	try	{	
		Form A2 = Form("A2 grade to sign too low", 0, 1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {	
		Form A2 = Form("A2 grade to execute too low", 1, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}		
	try {	
		Form A2 = Form("A2 grade to sign too high", 151, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try	{	
		Form A2 = Form("A2 grade to execute too high", 1, 151);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}	
	std::cout<< GREEN "-----END OF Form INITLIZATION FAIL TESTING-------" RESET <<std::endl;
}

/**
 * Tests show that Bureaucrats grade is lower than forms grade to sign an exception is thrown.
 * Test also shows that when excpetion is thrown, bob.signForm(*) does not get executed. 
 */
void testUnsignable()
{
	std::cout<< GREEN "-----START OF Form SIGNING FAIL TESTING-------" RESET <<std::endl;	
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low", 150);
		Form A2 = Form("A2", 1, 1);
		std::cout<<A2<<std::endl;
		bob.signForm(A2);
	} catch(const std::exception& e) {
	std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low", 6);
		Form A2 = Form("A2", 5, 1);
		std::cout<<A2<<std::endl;
		bob.signForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF Form SIGNING FAIL TESTING-------" RESET <<std::endl;
}

/**
 * Tests show when bureaucrats grade is high enough, form gets signed.  
 */
void showWorking2()
{
	std::cout<< GREEN "-----SART OF Form SHOW WORKING TESTING-------" RESET <<std::endl;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		Form A2 = Form("A2", 1, 1);
		std::cout<<A2<<std::endl;
		bob.signForm(A2);
		std::cout<<A2<<std::endl;

	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}	
	std::cout<< GREEN "-----END OF Form SHOW WORKING TESTING-------" RESET <<std::endl;
}

void runFtests()
{
	try {
		testinitilization2();	
		testUnsignable();
		showWorking2();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in runFtests "<<e.what() << '\n';
	}
}