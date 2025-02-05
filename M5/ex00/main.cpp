/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/16 13:30:25 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * @brief 
 * 
 * Forcing grade values too high and low and showing exception functionality 
 * 
 * @param test an object Bureaucrat
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
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	try {
		test = Bureaucrat("steve", 0);
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
}
/**
 * @brief 
 * 
 * forcing incremenation to cause too high or too low results and showing exception functionality
 * 
 * @param test an object_copy of  Bureaucrat
 * @param flag indicator give different behaviour based on if we send a default object 
 * to copy or if we need to set existing objects values for testing
 */
void	testIncrement(Bureaucrat& test, int flag)
{
	try {
		if (flag == 0)
			test = Bureaucrat("steve", 1);
		else
			test.setGrade(1);
		std::cout<<test<<std::endl;
		test.increaseGrade();
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	try {
		if (flag == 0)
			test = Bureaucrat("steve", 150);
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
int	main()
{
	Bureaucrat steve; 

	testInitilization(steve);
	testIncrement(steve, 0);
	try
	{
		Bureaucrat bob = Bureaucrat("bob", 150);
		testIncrement(bob, 1);
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	std::cout<<steve<<std::endl;
	try
	{
		showWorking(steve, 0);
	} catch(const std::exception& e) {
		std::cerr <<"Something went wrong::"<< e.what() << '\n';
	}
	//steve.increaseGrade(); // will abort because its outside a try and catch block, exception will cause abort
}