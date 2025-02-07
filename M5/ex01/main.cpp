/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 10:58:23 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"

/**
 * runBtests = are same tests as ex00, now showing that Bureaucrat still works
 * 
 * runFtests = form_tests on form
 */
int	main()
{
	try {
		runBtests();
	} catch(const std::exception& e) {
		std::cerr << "b tests Exception caught in main   ......." << '\n';
	}
	try {
		runFtests();
	} catch(const std::exception& e) {
		std::cerr << "a tests Exception caught in main " <<e.what() << '\n';
	}
	

}