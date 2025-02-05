/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:28:49 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/28 17:25:09 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	fillSpan(Span &vec, int size)
{
	for (int i = 0; i < size; i++)
		vec.addNumber(i);
}

void	fillVector(std::vector<int> &vec, int size)
{
	//std::cout<<"bug hunting 1 \n";
	vec.resize(size);
	for (int i = 0; i < size; i++)
		vec[i] = i;
	//std::cout<<"bug hunting 2 \n";

}

int main()
{
	/*Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr <<
		Span spp2 = Span(10000);
		spp2.addRange(spp.begin(), spp.end());pan(100);
		spp.addNumber(6);
		spp.addNumber(3);
		spp.addNumber(17);
		spp.addNumber(9);
		spp.addNumber(11);
		std::cout << spp.shortestSpan() << std::endl;
		std::cout << spp.longestSpan() << std::endl;
		spp.addNumber(12);
		spp.showArray();
	}
	{
		Span spp = Span(0);
		//Span spp1 = Span(1);
		Span spp2 = Span(2);
		try
		{
			//spp.addNumber(6);
			//spp1.addNumber(3);
			spp2.addNumber(17);
			spp2.addNumber(9);
			//spp.addNumber(11);
			//std::cout << spp.shortestSpan() << std::endl;
			//std::cout << spp.longestSpan() << std::endl;
			//std::cout << spp1.shortestSpan() << std::endl;
			//std::cout << spp1.longestSpan() << std::endl;

			std::cout << spp2.shortestSpan() << std::endl;
			std::cout << spp2.longestSpan() << std::endl;
			//spp.addNumber(12);
			spp.showArray();

		}
		catch(const std::exception& e)
		{
			std::cerr <<"faulre test caught in main "<< e.what() << '\n';
		}
	}*/
	{
		try
		{
		
			Span spp = Span(10000);
			std::vector<int> lol;
			fillVector(lol, 10000);//{1, 2, 3, 4, 5, 6};
			//std::cout<<"vecotrs first "<<lol[0]<<"\n";
			//Span spp2 = ;
			/*spp.addNumber(6);
			spp.addNumber(3);
			spp.addNumber(17);
			spp.addNumber(9);
			spp.addNumber(11);
			std::cout << spp.shortestSpan() << std::endl;
			std::cout << spp.longestSpan() << std::endl;
			spp.addNumber(12);*/
			fillSpan(spp, 10000);
			Span spp2 = Span(10000);
			spp2.addRange(lol.begin(), lol.end());
			spp2.showArray();
		}
		catch(const std::exception& e)
		{
			std::cerr <<"caughjt in main "<< e.what() << '\n';
		}
	}	
	return 0;
}