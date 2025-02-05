/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:56 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/17 16:59:05 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"

int	main()
{
	try {
		runBtests();
	} catch(const std::exception& e) {
		std::cerr << "b tests failed???  ......." << '\n';
	}
	try {
		runAtests();
	} catch(const std::exception& e) {
		std::cerr << "Exception caught in main " <<e.what() << '\n';
	}
	

}