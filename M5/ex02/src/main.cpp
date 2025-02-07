/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 12:19:49 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

/**
 * runBtests = are same tests as ex00, now showing that Bureaucrat still works
 * 
 * runFtests no longer relevent due to AForm being abstract
 * 
 * Following tests test each seperate class functionality 
 * 		President_tests();
 * 		Robot_tests();
 * 		Shrubbery_tests();
 * 
 */

int	main()
{
	try {
		runBtests();
	} catch(const std::exception& e) {
		std::cerr << "b tests failed???  ......." << '\n';
	}
	try {
		President_tests();
	} catch(const std::exception& e) {
		std::cerr << "Presidential Exception caught in main " <<e.what() << '\n';
	}
	try {
		Robot_tests();
	} catch(const std::exception& e) {
		std::cerr << "Robot Exception caught in main " << e.what() << '\n';
	}
	try {
		Shrubbery_tests();
	} catch(const std::exception& e) {
		std::cerr << "Shrubbery Exception caught in main " <<e.what() << '\n';
	}
	

}