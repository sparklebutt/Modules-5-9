/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/28 16:25:14 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <type_traits>
#include <string>

/**
 * @brief 
 * compariosn and swapping of values
 * 
 * @note These functions can be called with any type of argument. The only requirement is 
 * that the two arguments must have the same type and must support all the comparison operators. see example for extra
 * @tparam T 
 * @param a 1st
 * @param b 2nd
 */

 /**
  * @example can be applied into the functions to provide more indepth compiler error messages if variables provded can not utalize these compairson operators  
  * static_assert(std::is_convertible<decltype(a == b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the == operator.");
	static_assert(std::is_convertible<decltype(a >= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the >= operator.");
	static_assert(std::is_convertible<decltype(a <= b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the <= operator.");
	static_assert(std::is_convertible<decltype(a != b), bool>::value, "****HELOO SEE A PERSONAL MESSAGE min: Type must support the != operator.");
	static_assert(std::is_convertible<decltype(a > b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the > operator.");
	static_assert(std::is_convertible<decltype(a < b), bool>::value, "*****HELOO SEE A PERSONAL MESSAGE min: Type must support the < operator.");
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
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(const T &a, const T &b) {

	return a >= b ? b : a;
};

template<typename T>
T min(T &a, T &b) {
	return a >= b ? b : a;
};

template<typename T>
T max(const T &a, const T &b) {
	return a <= b ? b : a;
};

template<typename T>
T max(T &a, T &b) {
	return a <= b ? b : a;
};

