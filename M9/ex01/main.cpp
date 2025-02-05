/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:55:15 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/04 15:19:54 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc > 3)
	{
		std::cout<<" erro on argc \n";
		exit(EXIT_FAILURE);
	}
	try
	{
		RPN test(argv[1]);
		// could just print straight 
		double res = test.calculation();
		std::cout<<"res = "<<res<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//check that arg is clean 
	return 0;
}