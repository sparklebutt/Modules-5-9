/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 11:27:52 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/**
 * runBtests = are same tests as ex00, now showing that Bureaucrat still works
 * 
 * runFtests = form_tests on form
 */
int	main()
{
	/*try {
		runBtests();
	} catch(const std::exception& e) {
		std::cerr << "b tests failed???  ......." << '\n';
	}*/
	/*try {
		President_tests();
	} catch(const std::exception& e) {
		std::cerr << "Presidential Exception caught in main " <<e.what() << '\n';
	}*/
	/*try {
		Robot_tests();
	} catch(const std::exception& e) {
		std::cerr << "Robot Exception caught in main " <<e.what() << '\n';
	}*/
	/*try
	{
		Shrubbery_tests();
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Shrubbery Exceptions caught in main "<< e.what() << '\n';
	}*/
	try
	{
		Intern_tests();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}