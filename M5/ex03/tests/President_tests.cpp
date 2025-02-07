/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   President_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:35:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 10:56:19 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
/**
 * @brief adjusted for abstract class , can not instantiate Aform
 * 
 */
void testinitilizationPresident()
{
 	std::cout<< GREEN "-----START OF AForm President INITLIZATION-------" RESET <<std::endl;
	/*try {	
		AForm A2 = AForm("A2 grade to execute too low", 1, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}*/	
	try	{	
		PresidentialPardonForm A1;
		PresidentialPardonForm A2 = PresidentialPardonForm("Home");
	 	std::cout<< GREEN "-----START OF AForm copy-------" RESET <<std::endl;
		std::cout<<A1<<std::endl;
		A1 = A2;
		std::cout<<A1<<std::endl;
		PresidentialPardonForm A3(A1);
		std::cout<<A3<<std::endl;
		std::cout<< GREEN "-----END OF AForm copy-------" RESET <<std::endl;
	}	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm President INITLIZATION-------" RESET <<std::endl;
}
void testUnsignablePresident()
{
	std::cout<< GREEN "-----START OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;	
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low(150)", 150);
		PresidentialPardonForm A2 = PresidentialPardonForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 1" << '\n';
		std::cout<< GREEN "-----END OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;
	}
	try {
		std::cout<< GREEN "-----START OF AForm EXECUTION FAIL TESTING-------" RESET <<std::endl;	
		Bureaucrat bob = Bureaucrat("bob grade too low(6)", 6);
		PresidentialPardonForm A2 = PresidentialPardonForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 2" << '\n';
		std::cout<< GREEN "-----END OF AForm EXECUTION FAIL TESTING-------" RESET <<std::endl;
	}

}


void showWorkingPresident()
{
	std::cout<< GREEN "-----SART OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		PresidentialPardonForm A2 = PresidentialPardonForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		std::cout<<A2<<std::endl;
		bob.executeForm(A2);

	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
}

void President_tests()
{
	//president tests
	try {
		testinitilizationPresident();	
		testUnsignablePresident();
		showWorkingPresident();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in runFtests "<<e.what() << '\n';
	}

}