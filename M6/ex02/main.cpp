/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:38:23 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 14:38:29 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "generate.hpp"
#include <cstdlib> 
#include <stdexcept>
#include <iostream>
#include <type_traits>

int main()
{
	try
	{
		Base* looky = generate();

		identify(looky);
		identify(*looky);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 1;
}