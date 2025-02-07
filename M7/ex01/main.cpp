/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:08 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 11:50:50 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>
int test1(int num)
{
	return num + 1;
}

std::string test2(std::string done)
{
	return done + "done!";
}
struct Data {
	int attempts;
	bool locked;
	std::string message;
	
};

Data test3(Data& subject)
{
	if (subject.locked == true)
		subject.message = "\033[31m DONT PANIC \033[0m";	
	else if (subject.attempts == 2)
		subject.message = "1 more try left";
	else if (subject.attempts > 2)
	{
		subject.locked = true;
		subject.message = "account locked im watching you (0)(0)";
	}
	else
		subject.message = "Great succsess, you have logged in: ";
	return subject;
}
std::string TF(bool indicator)
{
	if (indicator == 0)
		return "false";
	else
		return "true";
}

int main()
{
	int array1[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"show old array elem = "<<array1[i]<<std::endl;
	::iter(array1, 5, test1);
	for (int i = 0; i < 5; i++)
		std::cout<<"show after iter fucn(ret num + 1) new array elem = "<<array1[i]<<std::endl;
	std::string array2[] {"aa", "bb", "cc", "dd", "ee"};
	for (int i = 0; i < 5; i++)
		std::cout<<"show old array string elem = "<<array2[i]<<std::endl;
	::iter(array2, 5, test2);
	for (int i = 0; i < 5; i++)
		std::cout<<"show after iter (string + done) new array string elem = "<<array2[i]<<std::endl;

	Data array3[] {{1, false, "welcome"},
	{1, false, "welcome"},
	{3, true, "network locked"},
	{3, false, "welcome"},
	{2, false, "welcome"}};

	for (int i = 0; i < 5; i++)
		std::cout<<"OLD array string elem attampts= "<<array3[i].attempts << "\n"
		<< "locked = " << TF(array3[i].locked) << "\n"
		<< "message ::" << array3[i].message<<std::endl;
	::iter(array3, 5, test3);
	for (int i = 0; i < 5; i++)
		std::cout<<"new array string elem attampts= "<<array3[i].attempts << "\n"
		<< "locked = " << TF(array3[i].locked) << "\n"
		<< "message ::" << array3[i].message<<std::endl;
	std::cout<<"-------------------------------------- "<<std::endl;
	int array4[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"old array elem = "<<array4[i]<<std::endl;
	::iter(array4, 5, increment<int>);
	for (int i = 0; i < 5; i++)
		std::cout<<"new array elem = "<<array4[i]<<std::endl;

	return 0;

	
}