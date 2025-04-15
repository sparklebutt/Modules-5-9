/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/14 12:16:05 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>

int main( void )
{

	std::cout<<"\033[0;32m----running const tests-----\n\033[0m";
	const int a = 2;
	const int b = 3;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::cout<<"\n\033[0;32m----running int tests-----\n\033[0m";	
	int aa = 2;
	int bb = 3;
	std::cout << "before swapping const int \naa = " << aa << ", bb = " << bb << std::endl;
	::swap( aa, bb );
	std::cout << "after swapping const int \naa = " << aa << ", bb = " << bb << std::endl;
	std::cout << "min( aa, bb ) = " << ::min( aa, bb ) << std::endl;
	std::cout << "max( aa, bb ) = " << ::max( aa, bb ) << std::endl;

	std::cout<<"\n\033[0;32m----running string tests-----\n\033[0m";
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "before swapping string \nc = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swapping string \nc = " << c << ", d = " << d << std::endl;	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout<<"\n\033[0;32m----running double tests-----\n\033[0m";
	double e = 2.1;
	double f = 3.5;
	std::cout<<"before swapping doubles \ne = "<<e<<" f = "<<f<<"\n";
	::swap( e, f );
	std::cout << "after swapping doubles \ne = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	return 0;
}