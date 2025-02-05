/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:55:12 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/23 10:10:21 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"

Base* generate() {
	// Seed the random number generator
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generate a random number between 0 and 2
	int randNum = std::rand() % 3;

	std::cout<<"random number =  "<<randNum<<" 0 = a 1 = b 2 = c\n";

	switch (randNum) {
		case 0:
		   return new ClassA();		
		case 1:
			return new ClassB();
		case 2:
			return new ClassC();
		default:
			return nullptr; // This should never happen
	}
}

void identify(Base* p)
{
	if (dynamic_cast<ClassA*>(p))
		std::cout<<"ClassA\n";
	else if (dynamic_cast<ClassB*>(p))
		std::cout<<"ClassB\n";
	else if (dynamic_cast<ClassC*>(p))
		std::cout<<"ClassC\n";
	else
		std::cout<<"Unknown\n";
}
void identify(Base& p)
{
	 try {
		// Try to cast to each type and catch std::bad_cast if it fails
		(void)dynamic_cast<ClassA&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<ClassB&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<ClassC&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	std::cout << "Unknown" << std::endl;
}