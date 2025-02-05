/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shrubbery_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:10:34 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 18:35:01 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "tests.hpp"

void testinitilizationShrubbery()
{
 	std::cout<< GREEN "-----START OF AForm Shruberry INITLIZATION-------" RESET <<std::endl;
	try	{	
		ShrubberyCreationForm A1;
		ShrubberyCreationForm A2 = ShrubberyCreationForm("Home");
	 	std::cout<< GREEN "-----START OF AForm copy-------" RESET <<std::endl;
		std::cout<<A1<<std::endl;
		A1 = A2;
		std::cout<<A1<<std::endl;
		ShrubberyCreationForm A3(A1);
		std::cout<<A3<<std::endl;
		std::cout<< GREEN "-----END OF AForm copy-------" RESET <<std::endl;
	}	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm Shruberry INITLIZATION-------" RESET <<std::endl;
}
void testUnsignableShrubbery()
{
	std::cout<< GREEN "-----START OF AForm Shruberry SIGNING FAIL TESTING-------" RESET <<std::endl;	
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low(150)", 150);
		ShrubberyCreationForm A2 = ShrubberyCreationForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 1" << '\n';
		std::cout<< GREEN "-----END OF AForm Shruberry SIGNING FAIL TESTING-------" RESET <<std::endl;
	}
	try {
		std::cout<< GREEN "-----START OF AForm Shruberry EXECUTION FAIL TESTING-------" RESET <<std::endl;	
		Bureaucrat bob = Bureaucrat("bob grade (6)", 6);
		Bureaucrat steve = Bureaucrat("steve grade too low(56)", 56);
		ShrubberyCreationForm A2 = ShrubberyCreationForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		steve.executeForm(A2);
		//bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 2" << '\n';
		std::cout<< GREEN "-----END OF AForm Shruberry EXECUTION FAIL TESTING-------" RESET <<std::endl;
	}
}

void showWorkingShrubbery()
{
	std::cout<< GREEN "-----START OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		ShrubberyCreationForm A2 = ShrubberyCreationForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		std::cout<<A2<<std::endl;
		bob.executeForm(A2);		
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
}

void Shrubberry_tests()
{
	try {
		testinitilizationShrubbery();	
		testUnsignableShrubbery();
		showWorkingShrubbery();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in Robot_tests"<<e.what() << '\n';
	}
}