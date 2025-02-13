/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:55:12 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 14:45:41 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generate.hpp"
#include <iostream>
#include <ctime>


Base* generate() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int randNum = std::rand() % 3;

	std::cout<<"random number =  "<<randNum<<" (0 = a) (1 = b) (2 = c)\n";
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

/**
 * parameter passed as pointer, pointers can hold a nullptr, therefore a simple if statement checks
 * to see if dynamic_cast returns a non null, if a nullptr is returned , we continue to try untill all have returned nullptr,
 * then an error message is printed.
 */
void identify(Base* p)
{
	if (dynamic_cast<ClassA*>(p))
		std::cout<<"ClassA\n";
	else if (dynamic_cast<ClassB*>(p))
		std::cout<<"ClassB\n";
	else if (dynamic_cast<ClassC*>(p))
		std::cout<<"ClassC\n";
	else
		std::cerr<<"ptr = nullptr\n";
}

/**
 * parameter passed as reference, refrences can not hold a nullptr,
 * We dynamically cast to see if it can be cast to Class provided,
 * if there is a bad cast, we catch do nothing and try the next one, we throw on failure
 * to cast class c as its the last cast to attempt and a true error has occured.
 */
void identify(Base& p)
{
	try {
		(void)dynamic_cast<ClassA&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::bad_cast&) {
		std::cerr<<"Class A bad cast trying B"<<std::endl;
	}
	try {
		(void)dynamic_cast<ClassB&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::bad_cast&) {
		std::cerr<<"Class B bad cast trying C"<<std::endl;
	}
	try {
		(void)dynamic_cast<ClassC&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::bad_cast&) {
		throw std::runtime_error("dynammic_cast to class C failed ");
	}
}