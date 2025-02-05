/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/21 15:08:34 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
/**
 * @brief adjusted for abstract class , can not instantiate Aform
 * 
 */
void testinitilizationIntern()
{
 	std::cout<< GREEN "-----START OF AForm Intern INITLIZATION-------" RESET <<std::endl;
	/*try {	
		AForm A2 = AForm("A2 grade to execute too low", 1, 0);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}*/	
	try	{
		Intern rando;
		AForm* rrf;
		rrf = rando.makeForm("robotomy request", "bender");
		std::cout<<*rrf<<std::endl;
		delete rrf;
	 	/*std::cout<< GREEN "-----START OF AForm copy-------" RESET <<std::endl;
		std::cout<<A1<<std::endl;
		A1 = A2;
		std::cout<<A1<<std::endl;
		PresidentialPardonForm A3(A1);
		std::cout<<A3<<std::endl;*/
		//std::cout<< GREEN "-----END OF Intern copy-------" RESET <<std::endl;
	}	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm Intern INITLIZATION-------" RESET <<std::endl;
}
void testUnsignableIntern()
{
	std::cout<< GREEN "-----START OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;	
	AForm* rrf;

	try {
		Bureaucrat bob = Bureaucrat("bob grade too low(150)", 150);
		Intern rando;
		rrf = rando.makeForm("robotomy request", "bender");
		bob.signAForm(*rrf);
		bob.executeForm(*rrf);
		delete rrf;

	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 1" << '\n';
		std::cout<< GREEN "-----END OF AForm SIGNING FAIL TESTING-------" RESET <<std::endl;
		delete rrf;

	}
	/*try {
		std::cout<< GREEN "-----START OF AForm EXECUTION FAIL TESTING-------" RESET <<std::endl;	
		Bureaucrat bob = Bureaucrat("bob grade too low(6)", 6);
		Intern rando;
		AForm* rrf;
		rrf = rando.makeForm("robotomy request", "bender");

		PresidentialPardonForm A2 = PresidentialPardonForm("Home");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 2" << '\n';
		std::cout<< GREEN "-----END OF AForm EXECUTION FAIL TESTING-------" RESET <<std::endl;
	}*/

}


void showWorkingIntern()
{
	std::cout<< GREEN "-----START OF AForm Intern SHOW WORKING TESTING-------" RESET <<std::endl;
	AForm* rrf;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		Intern rando;
		rrf = rando.makeForm("robotomy request", "bender");
		std::cout<<*rrf<<std::endl;
		bob.signAForm(*rrf);
		std::cout<<*rrf<<std::endl;
		bob.executeForm(*rrf);
		delete rrf;
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
		delete rrf;
	}
	std::cout<< GREEN "-----END OF AForm Intern SHOW WORKING TESTING-------" RESET <<std::endl;
}

void Intern_tests()
{
	//president tests
	try {
		testinitilizationIntern();	
		testUnsignableIntern();
		showWorkingIntern();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in runAtests "<<e.what() << '\n';
	}

}