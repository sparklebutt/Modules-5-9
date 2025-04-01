/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:08 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/28 16:58:19 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>
//#include <array>

int test1(int num) {
	return num + 1;
}

std::string test2(std::string done) {
	return done + "done!";
}

struct Data {
	int attempts;
	bool locked;
	std::string message;	
};

class ClassTest {
	private:
		int m_value;
	public:
		ClassTest() {};
		ClassTest(int val) : m_value(val) {};
		~ClassTest() {};
		int getVal() {return m_value;};
		int changeVal(int num) {return m_value += num;}
};

Data test3(Data& subject) {
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

std::string TF(bool indicator) {
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

	Data array3[] {
	{1, false, "welcome"},
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
	std::cout<<"--------------------Testing instatiated template function (+ 10 to value)------------------ "<<std::endl;
	int array4[] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout<<"old array elem = "<<array4[i]<<std::endl;
	::iter(array4, 5, increment_value<int>);
	for (int i = 0; i < 5; i++)
		std::cout<<"new array elem = "<<array4[i]<<std::endl;

	std::cout<<"--------------------Testing instatiated template function on multidimensioln carray(+ 10 to value)------------------ "<<std::endl;
	int cmultiarray[2][3] = {{1, 2, 3}, {4, 5, 6}};
	::iter(cmultiarray, 2, increment_value<int>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)
			std::cout<<"new array elem = "<<cmultiarray[i][x]<<std::endl;		
	}
	std::cout<<"--------------------Testing instatiated template function on multidimensioln aarray(+ 10 to value)------------------ "<<std::endl;
	int a = 1; int b = 2; int c = 3; int d = 4; int e = 5; int f = 6;
	int* mptrarray[2][3] = {{&a, &b, &c}, {&d, &e, &f}};	
	::iter(mptrarray, 2, increment_value<int>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)	
			std::cout<<"new array elem = "<<*mptrarray[i][x]<<std::endl;		
	}

	ClassTest classarray[] = {ClassTest(1), ClassTest(2), ClassTest(3)};
	::iter(classarray, 3, increment_cvalue<ClassTest>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)	
			std::cout<<"new array elem = "<<classarray[i].getVal()<<std::endl;		
	}

	double aa = 10;  double bb = 20; double cc = 30; double dd = 40; double ee = 50; double ff = 60;
	double* doubles[2][3] = {{&aa, &bb, &cc}, {&dd, &ee, &ff}};	
	::iter(doubles, 2, increment_value<double>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)	
			std::cout<<"new array elem = "<<*doubles[i][x]<<std::endl;		
	}
	return 0;	
}
	/*
	
	
		//print before
	//std::cout<<"--------------------Testing instatiated template function on type <array>(+ 10 to value)------------------ "<<std::endl;
	//std::array <int, 5> test = {1, 2, 3, 4, 5};
	//::iter(&test, 5, increment_plus<int>);
	//for (int i = 0; i < 5; i++)
	//	std::cout<<"new array elem = "<<test[i]<<std::endl;
	std::array <std::array<int, 3>, 2> amultiarray = {{{1, 2, 3}, {4, 5, 6}}};
	::iter(amultiarray, 2, increment<int>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)
			std::cout<<"new array elem = "<<amultiarray[i][x]<<std::endl;		
	}
	std::cout<<"--------------------Testing instatiated template func on ptr array(+ 10 to value)------------------ "<<std::endl;

	//double a = 1; double b = 2; double c = 3; //double d = 4; double e = 5; double f = 6;
	int* cptrarray[] = {&a, &b, &c};	
	::iter(cptrarray, 3, increment<int>);
	for (int i = 0; i < 3; i++)
	{
		std::cout<<"new array elem = "<<*cptrarray[i]<<std::endl;		
	}
	std::cout<<"--------------------Testing instatiated template func on std ptr array( org + 1 and + 10 to value)------------------ "<<std::endl;	
	std::array <int*, 3> ptrarray = {&a, &b, &c};	
	::iter(ptrarray, 3, increment<int>);
	for (int i = 0; i < 3; i++)
	{
		std::cout<<"new array elem = "<<*ptrarray[i]<<std::endl;		
	}
	std::cout<<"--------------------Testing instatiated template func on multi dimensiol ptr array( org + 1 and + 10 to value)------------------ "<<std::endl;
	std::cout<<"--------------------Testing instatiated template func on multi dimensiol std array type ptr array( org + 1 and + 10 to value)------------------ "<<std::endl;
	std::array <std::array<int*, 3>, 2> msptrarray = {{{&a, &b, &c}, {&d, &e, &f}}};	
	::iter(msptrarray, 2, increment<int>);
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 3; x++)		
			std::cout<<"new array elem = "<<*msptrarray[i][x]<<std::endl;		
	}

*/
