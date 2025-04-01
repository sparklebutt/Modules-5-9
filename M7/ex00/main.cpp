/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:05 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/28 16:43:02 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
#include <type_traits>
#include <memory>

/**
 * comment out compariosn operators to see how static asserts catch the lack of them
 */
class Test {
	private:
		int m_value;
	public:	
		Test() {};
		Test(int val) : m_value(val) {};
		~Test() {};
		int getVal() {return m_value;};

		bool operator>=(const Test& other) const {
			return m_value >= other.m_value;
		}
	
		bool operator<=(const Test& other) const {
			return m_value <= other.m_value;
		}
	
		bool operator>(const Test& other) const {
			return m_value > other.m_value;
		}
	
		bool operator<(const Test& other) const {
			return m_value < other.m_value;
		}
		
};

struct customTester
{
	int value;
	// Define the comparison operators
    bool operator==(const customTester& other) const {
        return value == other.value;
    }

    bool operator!=(const customTester& other) const {
        return value != other.value;
    }

    bool operator<(const customTester& other) const {
        return value < other.value;
    }

    bool operator>(const customTester& other) const {
        return value > other.value;
    }

    bool operator<=(const customTester& other) const {
        return value <= other.value;
    }

    bool operator>=(const customTester& other) const {
        return value >= other.value;
    }
};

std::ostream& operator<<(std::ostream& os, const customTester& obj) { os << obj.value; return os;};

int main( void )
{
	std::cout<<"\033[0;34m----expected outcome ---- \na = 2, b = 3 \n" 
	<<"min(a, b) = 2 \n"
	<<"max(a, b) = 3 \n"
	<<"c = chaine2, d = chaine1 \n"
	<<"min(c, d) = chaine1 \n"
	<<"max(c, d) = chaine2 \n-------------------\n \033[0m----running tests----------\n";
	
	std::cout<<"\033[0;32m----running provided tests-----\n\033[0m";
	const int a = 2;
	const int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout<<"\n\033[0;32m----running decimal tests-----\n\033[0m";
	double e = 2.1;
	double f = 3.5;
	std::cout<<"\n\033[0me = "<<e<<" f = "<<f<<"\n";
	::swap( e, f );
	std::cout<<"\033[0;31mvalues swapped\n\033[0m";
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	
	std::cout<<"\n\033[0;32m----running struct tests-----\n\033[0m";
	customTester test1{1};
	customTester test2{2};
	std::cout << "test1 = " << test1.value << ", test2 = " << test2.value << std::endl;
	::swap(test1, test2);
	std::cout<<"\033[0;31mvalues swapped (example.value)\n\033[0mtest1 = "<<test1.value<<" test2 = "<<test2.value<<"\n";
	std::cout<<"\033[0;31mvalues shown as non value swapped (example)\n\033[0mtest1 = "<< test1<<" test2 = "<<test2<<"\n";

	std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
	std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;
	
	std::cout<<"\n\033[0;32m----running string tests-----\n\033[0m";
	std::string g = "of the chaine bling bling";
	std::string h = "chaineP";
	std::cout << "\033[0;31mstrings before swap  \033[0m g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "\033[0;31mstrings after swap  \033[0m g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	Test aa(44);
	Test bb(55);
	
	std::cout<<"\n\033[0;32m----running class tests-----\n\033[0m";
	std::cout << "\033[0;31mbefore swap: \033[0m aa = " << aa.getVal() << ", bb = " << bb.getVal() << std::endl;	
	::swap(aa, bb);
	std::cout << "\033[0;31mafter swap: \033[0m: aa = " << aa.getVal() << ", bb = " << bb.getVal() << std::endl;	
	Test returna(::min( aa, bb ));
	std::cout << "min( aa, bb ) = " << returna.getVal()<< std::endl;
	Test returnb(::max( aa, bb ));	
	std::cout << "max( aa, bb ) = " << returnb.getVal()<< std::endl;

	std::cout << "----fail test commented out as they cause compiler error as they should-----\n";
	//::min(void);
	//::swap(e, test1);
	//std::unique_ptr<int> ptr1(new int(1));
	//std::unique_ptr<int> ptr2(new int(2));
	//::swap(ptr1, ptr2);
	return 0;
}

/**
 * @brief 
 * 
 * testing compiler error to see how static_assert works not required for evaluation but left for 
 * curiouse minds
 * 	@example 
 * try
	{
		::swap( test1, test2 );
		std::cout << "test1 = " << test1.value << ", test2 = " << test2.value << std::endl;
		//std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
		//std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr<<"failure caught in main " << e.what() << '\n';
	}

	try
	{
		std::cout << "min( test1, test2 ) = " << ::min( test1, test2 ) << std::endl;
		std::cout << "max( test1, test2 ) = " << ::max( test1, test2 ) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "failure caught in main min max"<< e.what() << '\n';
	}
 */