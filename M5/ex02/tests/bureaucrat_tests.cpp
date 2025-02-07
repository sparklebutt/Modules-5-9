/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:29:59 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 15:01:33 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**
 * @brief 
 * 
 * Forcing grade values too high and low and showing exception functionality 
 * 
 * @param test an object Bureaucrat
 */
void	testInitilization(Bureaucrat& test)
{
	std::cout<< GREEN "-----START OF BUREAUCRAT INITILIZATION TESTS-------" RESET <<std::endl;
	try	{
		test = Bureaucrat("steve too high", 151);
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	try {
		test = Bureaucrat("steve too low", 0);
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	std::cout<< GREEN "-----END OF BUREAUCRAT INITILIZATION TESTS-------" RESET <<std::endl;
}
/**
 * @brief 
 * 
 * forcing incremenation to cause too high or too low results and showing exception functionality
 * 
 * @param test an object_copy of  Bureaucrat
 * @param flag indicates if we are sending a default object (values not initialized), or object with values
 * initialized. if 0 copy constructor inits values to test. (showing copy constructor working as intended)
 */
void	testIncrement(Bureaucrat& test, int flag)
{
	try {
		if (flag == 0)
			test = Bureaucrat("steve++", 1);
		else
			test.setGrade(1);
		std::cout<<test<<std::endl;
		test.increaseGrade();
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	try {
		if (flag == 0)
			test = Bureaucrat("steve--", 150);
		else
			test.setGrade(150);
		std::cout<<test<<std::endl;
		test.decreaseGrade();
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
}

void showWorking(Bureaucrat& test, int flag)
{
	int i = 0;
	test = Bureaucrat("steve", 1);
	if (flag == 0)
	{
		while (i < 10 && ++i)
		{
			std::cout<<test<<std::endl;
			test.decreaseGrade();
		}
		while (i > 0)
		{
			std::cout<<test<<std::endl;
			test.increaseGrade();
			i--;
		}		
		flag = 1;
	}
	if (flag == 1)
	{
		Bureaucrat bob = Bureaucrat("bob", 1);		
		while (i < 10 && ++i)
		{
			std::cout<<bob<<std::endl;
			bob.decreaseGrade();
		}
		while (i > 0)
		{
			std::cout<<bob<<std::endl;
			bob.increaseGrade();
			i--;
		}		

	}
}

/**
 * @example 	AForm A2; compiler error, can not be instantiated
 */
void runBtests()
{
	Bureaucrat steve; 

	testInitilization(steve);
	std::cout<<"test incremenets"<<std::endl;
	testIncrement(steve, 0);
	try
	{
		std::cout<< GREEN "-----START OF BUREAUCRAT INCREMENT TESTS-------" RESET <<std::endl;
		Bureaucrat bob = Bureaucrat("bob", 150);
		testIncrement(bob, 1);
		std::cout<< GREEN "-----END OF BUREAUCRAT INCREMENT TESTS-------" RESET <<std::endl;
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	std::cout<<steve<<std::endl;
	try
	{
		std::cout<< GREEN "-----START OF BUREAUCRAT SHOW WORKING TESTS-------" RESET <<std::endl;
		showWorking(steve, 0);
		std::cout<< GREEN "-----END OF BUREAUCRAT SHOW WORKING TESTS-------" RESET <<std::endl;
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}

}