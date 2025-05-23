/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 14:01:12 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Array.hpp"
#include <limits>

#define MAX_VAL 10
#define RANGE 10
/**
 * @brief helper fucntions for testing , if you want to look inside the arrays
 * 
 */
template <typename T>
void printArray(const Array<T>& arr, unsigned int size, const std::string& name) {
    std::cout <<"size of array: " << name << " = " << size << " " << std::endl;
	for (unsigned int i = 0; i < size; ++i) {
		std::cout << " index i = " << i
        << " with a value of = --" << arr[i] << "--\n";
	}
	if (size == 0) {
		std::cout<<"array empty"<<std::endl;
	}
    std::cout << std::endl;
}

template <typename T>
void fillArray(Array<T>& arr, unsigned int size, const std::string& name, T adding) {
	std::cout <<"size of array: " << name << " = " << size << " " << std::endl;
	for (unsigned int i = 0; i < size; ++i) {
		std::cout << " index i = " << i
        << " adding with a value of = --" << adding << "--\n";
		arr[i] = adding;
		adding++;
	}
	if (size == 0) {
		std::cout<<"array empty"<<std::endl;
	}
    std::cout << std::endl;
}

void printMirror(int* arr, unsigned int size, const std::string& name) {
	std::cout <<"size of array: " << name << " = " << size << " " << std::endl;
    for (std::size_t i = 0; i < size; ++i) {
		std::cout << " index i = " << i
        << " with a value of = --" << arr[i] << "--\n";
    }
    std::cout << std::endl;
}

// this test just shows that i dont allow type sign swapping utalizing a 
// flag in the makefile. as catching a minus number wth unsigned int is unsafe.

/*void testCompFail()
{
	try	{
		Array<int> numbers(-10);
		printArray(numbers, numbers.getSize(), "numbers");	
	} catch(const std::exception& e) {
		std::cerr << "test instatiation with minus number failed::" << '\n';
		throw;
	}
	try {
		Array<int> numbers(RANGE);
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr <<"minus number " << e.what() << '\n';
	}

}*/

void testEmpty()
{
	try	{
		std::cout<<"---Testing default constructor---"<<std::endl;
		Array<int> empty;
		printArray(empty, empty.getSize(), "empty");
	} catch(const std::exception& e) {
		std::cerr << "Test empty failed::" << '\n';
		throw;
	}
	try	{
		std::cout<<"---Testing parameterized constructor with n = 0---"<<std::endl;	
		Array<int> empty(0);
		printArray(empty, empty.getSize(), "empty");
	} catch(const std::exception& e) {
		std::cerr << "Test empty failed with param::" << '\n';
		throw;
	}
}

void 	testBaisic()
{
	try	{
		Array<int> numbers(10);
		printArray(numbers, numbers.getSize(), "numbers");	
	} catch(const std::exception& e) {
		std::cerr << "test baisic values should not fail::" << '\n';
		throw;
	}
	try
	{
		Array<int> numbers(10);
		fillArray(numbers, 10, "adding to numbers", 1);
		printArray(numbers, numbers.getSize(), "numbers");	
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<char> chars(10);
		fillArray(chars, 10, "adding to chars", 'a');
		printArray(chars, chars.getSize(), "chars");	
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testOutOfRange()
{
	Array<int> numbers(RANGE);
	std::cout<<"\t------START out of range tests----\n";
	try {
		numbers[RANGE] = 0;
	} catch(const std::exception& e) {
		std::cerr << "RANGE ( if range = 10, indexing should be max 9 )"<<e.what() << '\n';
	}
	try {
		numbers[RANGE] = RANGE + 1;
	} catch(const std::exception& e) {
		std::cerr << "RANGE + 1 "<<e.what() << '\n';
	}
	try {
		Array<int> empty;
		empty[0] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout<<"\t------END out of range tests----\n\n";

}

void testCopys()
{
	std::cout<<"making array \n";		
	Array<int> numbers(MAX_VAL);
	std::cout<<"making mirror \n";
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (unsigned int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	printArray(numbers, MAX_VAL, "numbers");
	std::cout<<"\t------START copies tests----\n";
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		if (&numbers == &tmp || &numbers == &test || &test == &tmp)
			throw std::runtime_error("WRONG:: addresses match oopsies");
		std::cout<<"adress of numbers "<<&numbers<<"\n";
		std::cout<<"adress of tmp "<<&tmp<<"\n";
		std::cout<<"adress of test "<<&test<<"\n";
	}
	for (unsigned int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i]) {
			throw std::runtime_error("ERROR: values do not match ");
		}
	}

	printArray(numbers, MAX_VAL, "numbers");
	printMirror(mirror, MAX_VAL, "mirror");
	delete [] mirror;
	std::cout<<"\t------END copies tests----\n\n";
}

int main(int, char**)
{
	/*try
	{
		testCompFail();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}*/
	try	{
		testEmpty();
	} catch(const std::exception& e) {
		std::cerr <<"exception caught in main: testFail() failed : "<< e.what() << '\n';
	}
	/*try	{
		testBaisic();
	} catch(const std::exception& e) {
		std::cerr <<"exception caught in main: testBaisic() failed : "<< e.what() << '\n';
	}
	try {
		testOutOfRange();
	} catch(const std::exception& e) {
		std::cerr <<"out of ranneg fail????? "<< e.what() << '\n';
	}
	try	{
		testCopys();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}*/
	return 0;
}