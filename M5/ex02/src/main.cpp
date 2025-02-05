/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 17:43:06 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	try
	{
		Shrubberry_tests();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}