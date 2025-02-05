/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/24 11:48:59 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cppint * a = new int();

	std::cout<<"display elements "<<a<<"\n";

 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

/**
 * @brief helper fucntions for testing , if you want to look inside the arrays
 * 
 */
void printArray(const Array<int>& arr, std::size_t size, const std::string& name) {
    std::cout << name << " array values: ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void printMirror(int* arr, std::size_t size, const std::string& name) {
    std::cout << name << " array values: ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int, char**)
{
	std::cout<<"making array \n";		
	Array<int> numbers(MAX_VAL);
	std::cout<<"making mirror \n";
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
//	printArray(numbers, MAX_VAL, "numbers");
	//SCOPE
	std::cout<<"\t------START copies tests----\n";
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		if (&numbers == &tmp || &numbers == &test || &test == &tmp)
			std::cout<<"WRONG:: addresses match oopsies\n";
		std::cout<<"adress of numbers "<<&numbers<<"\n";
		std::cout<<"adress of tmp "<<&tmp<<"\n";
		std::cout<<"adress of test "<<&test<<"\n";
	}
	std::cout<<"\t------END copies tests----\n\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout<<"\t------START out of range tests----\n";
	try {
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr <<"minus number " <<e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch(const std::exception& e) {
		std::cerr << "0 "<<e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = MAX_VAL + 1;
	} catch(const std::exception& e) {
		std::cerr << "MAX_VAL + 1 "<<e.what() << '\n';
	}
	std::cout<<"\t------END out of range tests----\n\n";

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	// showing that numbers array still exists so mirror and numbers are not the same object
	//printArray(numbers, MAX_VAL, "numbers");

	return 0;
}