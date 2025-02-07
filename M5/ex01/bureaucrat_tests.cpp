/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:29:59 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 10:57:27 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * @brief 
 * 
 * Forcing grade values too high and low and showing exception functionality 
 * 
 * @param test an object Bureaucrat
 * 
 * Given example shows how we could catch only those specific custom exceptions,
 * In this case it would add unneccisary complexion to the code.
 * Catching custome exception by "customeName& e" allows us to adjust behaviour
 * around only that exception.
 * 
 * @example  catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "caught exception in main :: " <<e.what() << '\n';
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "caught exception in main :: " <<e.what()<< '\n';
	}
 */
void	testInitilization(Bureaucrat& test)
{
	try	{
		test = Bureaucrat("steve", 151);
	} catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "custom exception in main :: " <<e.what() << '\n'; } 
	catch(const std::exception& e) {
		std::cerr <<"Exception caught Test initilization ::"<< e.what() << '\n';
	}
	try {
		test = Bureaucrat("steve", 0);
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "custome exception in main :: " <<e.what()<< '\n'; }
	catch(const std::exception& e) {
		std::cerr <<"Exception caught Test initilization::"<< e.what() << '\n';
	}
}

/**
 * @brief 
 * 
 * forcing incremenation to cause too high or too low results and showing exception functionality
 * 
 * @param test an object_copy of  Bureaucrat
 * @param flag indicates if we are sending a default object (values not initialized), or object with values
 * initialized. if flag = 0, copy constructor inits values to test. (showing copy constructor working as intended)
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
 * @example 
 * steve.increaseGrade(); will abort when its outside a try and catch block, exception will cause abort
 * this is expected behaviour.
 * 
 */
void runBtests()
{
	Bureaucrat steve; 

	testInitilization(steve);
	std::cout<<"test incremenets"<<std::endl;
	testIncrement(steve, 0);
	try {
		std::cout<< GREEN "-----START OF BUREAUCRAT INCREMENT TESTS-------" RESET <<std::endl;
		Bureaucrat bob = Bureaucrat("bob", 150);
		testIncrement(bob, 1);
		std::cout<< GREEN "-----END OF BUREAUCRAT INCREMENT TESTS-------" RESET <<std::endl;
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	std::cout<<steve<<std::endl;
	try {
		std::cout<< GREEN "-----START OF BUREAUCRAT SHOW WORKING TESTS-------" RESET <<std::endl;
		showWorking(steve, 0);
		std::cout<< GREEN "-----END OF BUREAUCRAT SHOW WORKING TESTS-------" RESET <<std::endl;
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
}