/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:28:49 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 17:17:15 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	fillSpan(Span &vec, int size)
{
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
	for (int i = 0; i < size; i++) {
		int random_number =  1 + rand() % size / 2 + i;       // Generate a random number between 1 and 10
		//std::cout << "Random number between 1 and 10 is: " << random_number << std::endl;
		vec.addNumber(random_number);	
	}

}

void	fillVector(std::vector<int> &vec, int size)
{
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator	
	//std::cout<<"bug hunting 1 \n";
	vec.resize(size);
	for (int i = 0; i < size; i++) {
		int random_number = 1 + rand() % size + 10;       // Generate a random number between 1 and 10
		vec[i] = random_number;		
	}
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
			fillSpan(spp, 10000);
			
			std::cout<<"show shortest span = "<< spp.shortestSpan()
			<< "\nshow longest span = " << spp.longestSpan()<<std::endl; 

			std::vector<int> lol;
			fillVector(lol, 10);//{1, 2, 3, 4, 5, 6};
			
			//std::cout<<"vecotrs first "<<lol[0]<<"\n";
			// Span spp0 = ;
			/*spp.addNumber(6);
			spp.addNumber(3);
			spp.addNumber(17);
			spp.addNumber(9);
			spp.addNumber(11);
			std::cout << spp.shortestSpan() << std::endl;
			std::cout << spp.longestSpan() << std::endl;
			spp.addNumber(12);*/
			//fillSpan(spp, 10000);
			Span spp2 = Span(10);
			fillSpan(spp2, 10);
			//spp2.addRange(lol.begin(), lol.end());
			std::cout<<"show shortest span = "<< spp2.shortestSpan()
			<< "\nshow longest span = " << spp2.longestSpan()<<std::endl; 
			spp2.showArray();
			std::cout<<"showing range of iterators"<<std::endl;
			Span spp3 = Span(10);
			spp3.addRange(lol.begin(), lol.end());	
			spp3.showArray();
		}
		catch(const std::exception& e)
		{
			std::cerr <<"caught in main "<< e.what() << '\n';
		}
	}	
	return 0;
}