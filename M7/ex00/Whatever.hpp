/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/05 11:48:22 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <type_traits>
#include <string>

/**
 * @brief 
 * 
 * passing by reference to reduce copies
 * 
 * I have included the static_assert which can be commented out during testing, 
 * This is just showing how we can manipulate compiler messages to  give clearer messages.
 * These messages can be customizable and give very concice information. 
 * @note These functions can be called with any type of argument. The only requirement is 
 * that the two arguments must have the same type and must support all the comparison operators.
 * @tparam T 
 * @param a 1st
 * @param b 2nd
 */

 /**
  * This swap function should not really exists, but the subject was left unclear on if it was required,
  * as it is not forbidden in the subject i have left it to show case how it is possible.
  */
template<typename T>
void swap(const T &a, const T &b) {
    T& nonConstA = const_cast<T&>(a); // Remove constness from 'a'
    T& nonConstB = const_cast<T&>(b); // Remove constness from 'b'

    T temp = nonConstA;
    nonConstA = nonConstB;
    nonConstB = temp;
}

template<typename T>
void swap(T &a, T &b) {
	/*static_assert(std::is_convertible<decltype(a == b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE swap: Type must supprt the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE swap: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE swap: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE swap: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE swap: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE swap : Type must support the < operator.");
	static_assert(std::is_copy_assignable<T>::value, "******HELOO SEE A PERSONAL MESSAGE swap: Type must be copy assignable.");*/
	T temp = a;
	a = b;
	b = temp;
}
/**
 * @example 	static_assert(std::is_convertible<decltype(a <=> b), bool>::value, 
				  "*****************HELOO SEE A PERSONAL MESSAGE max: Type must supprt the <=>  operator.");
				  this check has not been added as its in the c++20
 */
template<typename T>
T min(const T &a, const T &b) {
	/*static_assert(std::is_convertible<decltype(a == b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the < operator.");*/
	return a >= b ? b : a;
};

template<typename T>
T min(T &a, T &b) {
	/*static_assert(std::is_convertible<decltype(a == b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the < operator.");*/
	return a >= b ? b : a;
};

template<typename T>
T max(const T &a, const T &b) {
	/*static_assert(std::is_convertible<decltype(a == b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must supprt the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "******HELOO SEE A PERSONAL MESSAGE max: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "******HELOO SEE A PERSONAL MESSAGE max: Type must support the < operator.");*/
	return a <= b ? b : a;
};

template<typename T>
T max(T &a, T &b) {
	/*static_assert(std::is_convertible<decltype(a == b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must supprt the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE max: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "******HELOO SEE A PERSONAL MESSAGE max: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "******HELOO SEE A PERSONAL MESSAGE max: Type must support the < operator.");*/
	return a <= b ? b : a;
};

