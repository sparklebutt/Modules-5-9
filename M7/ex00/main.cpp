/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 11:41:36 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
//fail testing libs
#include <type_traits>
#include <memory>

int main( void )
{
	std::cout<<"----expected out come ---- \na = 3, b = 2 \n" 
	<<"min(a, b) = 2 \n"
	<<"max(a, b) = 3 \n"
	<<"c = chaine2, d = chaine1 \n"
	<<"min(c, d) = chaine1 \n"
	<<"max(c, d) = chaine2 \n-------------------\n----running tests----------\n";
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	double e = 2.1;
	double f = 3.5;
	::swap( a, b );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::string g = "chaine1";
	std::string h = "chaine2";
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	std::cout << "----fail test-----\n";
	//std::unique_ptr<int> ptr1(new int(1));
	//std::unique_ptr<int> ptr2(new int(2));
	//::swap(ptr1, ptr2);
	//customFail test1{1};
	//customFail test2{2};
	return 0;
}

/**
 * @brief 
 * 
 * testing compiler error to see how static_assert works
 * 	@example 
 * try
	{
		::swap( test1, test2 );
		std::cout << "test1 = " << test1.value << ", test2 = " << test2.value << std::endl;
		//std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
		//std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr<<"failure caught in main " << e.what() << '\n';
	}

	try
	{
		std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
		std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "failure caught in main min max"<< e.what() << '\n';
	}
 */