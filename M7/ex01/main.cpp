/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:08 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 13:51:11 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void test1(int &num) {
	num += 1;
}

void test2(std::string &done) {
	done += " done!";
}

int main()
{
	std::cout<<"\033[0;32m----running int array test-----\n\033[0m";
	int array1[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"show old array elem = "<<array1[i]<<std::endl;
	::iter(array1, 5, test1);
	for (int i = 0; i < 5; i++)
		std::cout<<"show after iter func(ret num + 1) new array elem = "<<array1[i]<<std::endl;

	std::cout<<"\033[0;32m----running int const array test-----\n\033[0m";
	int const arrayconst[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"show old array elem = "<<arrayconst[i]<<std::endl;
	::iter(arrayconst, 5, show_const<int const>);

	std::cout<<"\033[0;32m----running string array test-----\n\033[0m";	
	std::string array2[] {"aa", "bb", "cc", "dd", "ee"};
	for (int i = 0; i < 5; i++)
		std::cout<<"show old array string elem = "<<array2[i]<<std::endl;
	::iter(array2, 5, test2);
	for (int i = 0; i < 5; i++)
		std::cout<<"show after iter (string + done) new array string elem = "<<array2[i]<<std::endl;
		
	std::cout<<"\033[0;32m----running int array test (instantiated template fucntion)-----\n\033[0m";
	int array4[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"old array elem = "<<array4[i]<<std::endl;
	::iter(array4, 5, increment_value<int>);
	for (int i = 0; i < 5; i++)
		std::cout<<"new array elem ( after + 10) = "<<array4[i]<<std::endl;

	std::cout<<"\033[0;32m----running multidimensional int array test (instantiated template function)-----\n\033[0m";	
	int cmultiarray[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++)
			std::cout<<"old array elem = "<<cmultiarray[i][x]<<std::endl;
	}
	::iter<int, 3, 3>(cmultiarray, 3, increment_value<int>);
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++)
			std::cout<<"new array elem = "<<cmultiarray[i][x]<<std::endl;		
	}
	// this section shows how we can add value to the address and change values of the variables. 
	int a = 1; int b = 2; int c = 3;
	int* mptrarray[] = {&a, &b, &c};	
	for (int i = 0; i < 3; i++) {
		std::cout<<"old array elem for the pointers= "<<*mptrarray[i]<<std::endl;		
	}
	::iter<int *>(mptrarray, 3, increment_value<int *>);
	for (int i = 0; i < 3; i++) {
		std::cout<<"new array elem for the ointers= "<<*mptrarray[i]<<std::endl;		
	}
	return 0;	
}