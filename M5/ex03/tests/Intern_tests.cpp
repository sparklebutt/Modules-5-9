/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 15:34:55 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "tests.hpp"
/**
 * @brief can not instantiate Aform as it has been declared abstract
 * adjust formType and name in tests.hpp  
 * 
 */


void testinitilizationIntern()
{
	AForm* rrf = nullptr;
 	std::cout<< GREEN "-----START OF AForm Intern INITLIZATION-------" RESET <<std::endl;
	try	{
		Intern rando;
		rrf = rando.makeForm(formType, name);
		std::cout<<*rrf<<std::endl;
		delete rrf;
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in Intern_tests" <<e.what() << '\n';
		if (rrf)
			delete rrf;
	}
	std::cout<< GREEN "-----END OF AForm Intern INITLIZATION-------\n" RESET <<std::endl;
}

void testUnsignableIntern()
{
	std::cout<< GREEN "\n-----START OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;	
	AForm* rrf = nullptr;

	try {
		Bureaucrat bob = Bureaucrat("bob grade too low(150)", 150);
		Intern rando;
		rrf = rando.makeForm(formType, name);
		bob.signAForm(*rrf);
		bob.executeForm(*rrf);
		delete rrf;

	} catch(const std::exception& e) {
		std::cerr << "unsignableintern exception caught in Intern_tests" <<e.what()<< '\n';
		std::cout<< GREEN "-----END OF AForm SIGNING FAIL TESTING-------\n" RESET <<std::endl;
		if (rrf)
			delete rrf;
	}
}

void showWorkingIntern()
{
	std::cout<< GREEN "\n-----START OF AForm Intern SHOW WORKING TESTING-------" RESET <<std::endl;
	AForm* rrf;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		Intern rando;
		rrf = rando.makeForm(formType, name);
		std::cout<<*rrf<<std::endl;
		bob.signAForm(*rrf);
		std::cout<<*rrf<<std::endl;
		bob.executeForm(*rrf);
		delete rrf;
	} catch(const std::exception& e) {
		if (rrf)
			delete rrf;
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm Intern SHOW WORKING TESTING-------" RESET <<std::endl;
}

void Intern_tests()
{
	try {
		testinitilizationIntern();	
		testUnsignableIntern();
		showWorkingIntern();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in runFtests "<<e.what() << '\n';
	}

}