/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:42:08 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 15:56:05 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "RobotomyRequestForm.hpp"

void testinitilizationRobot()
{
 	std::cout<< GREEN "-----START OF AForm Robot INITLIZATION-------" RESET <<std::endl;
	try	{	
		RobotomyRequestForm A1;
		RobotomyRequestForm A2 = RobotomyRequestForm("bender");
	 	std::cout<< GREEN "-----START OF AForm copy-------" RESET <<std::endl;
		std::cout<<A1<<std::endl;
		A1 = A2;
		std::cout<<A1<<std::endl;
		RobotomyRequestForm A3(A1);
		std::cout<<A3<<std::endl;
		std::cout<< GREEN "-----END OF AForm copy-------" RESET <<std::endl;
	}	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm Robot INITLIZATION-------" RESET <<std::endl;
}
void testUnsignableRobot()
{
	std::cout<< GREEN "-----START OF AForm Robot SIGNING FAIL TESTING-------" RESET <<std::endl;	
	try {
		Bureaucrat bob = Bureaucrat("bob grade too low(150)", 150);
		RobotomyRequestForm A2 = RobotomyRequestForm("bender");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 1" << '\n';
		std::cout<< GREEN "-----END OF AForm Robot SIGNING FAIL TESTING-------" RESET <<std::endl;
	}
	try {
		std::cout<< GREEN "-----START OF AForm Robot EXECUTION FAIL TESTING-------" RESET <<std::endl;	
		Bureaucrat bob = Bureaucrat("bob grade (6)", 6);
		Bureaucrat steve = Bureaucrat("steve grade too low(56)", 56);
		RobotomyRequestForm A2 = RobotomyRequestForm("bender");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		steve.executeForm(A2);
		//bob.executeForm(A2);
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests 2" << '\n';
		std::cout<< GREEN "-----END OF AForm Robot EXECUTION FAIL TESTING-------" RESET <<std::endl;
	}
}

void showWorkingRobot()
{
	int yes = 0;
	std::cout<< GREEN "-----SART OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
	try {
		Bureaucrat bob = Bureaucrat("bob", 1);
		RobotomyRequestForm A2 = RobotomyRequestForm("bender");
		std::cout<<A2<<std::endl;
		bob.signAForm(A2);
		std::cout<<A2<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			try
			{
				bob.executeForm(A2);		
				yes++;
			}
			catch(const std::exception& e)
			{	
				std::cerr <<"yikes something failed" << '\n';
			}
		}
		std::cout<<yes<<"times looped "<<std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in tests" << e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF AForm SHOW WORKING TESTING-------" RESET <<std::endl;
}

void Robot_tests()
{
	// not always 50%
	srand(time(NULL));
	try {
		testinitilizationRobot();	
		testUnsignableRobot();
		showWorkingRobot();
	} catch(const std::exception& e) {
		std::cerr << "Something caught in Robot_tests"<<e.what() << '\n';
	}
}
