/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/23 12:38:18 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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
 * @tparam T 
 * @param a 1st
 * @param b 2nd
 */
template<typename T>
void swap(T &a, T &b) {
	static_assert(std::is_copy_assignable<T>::value, "Type must be copy assignable.");
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T min(T &a, T &b)
{
	static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, 
             "HELOO SEE PERSONAL MESSAGE Type must support comparison operators.");
	return a >= b ? b : a;
}

template<typename T>
T max(T &a, T &b)
{
	static_assert(std::is_arithmetic<T>::value || std::is_same<T, std::string>::value, 
	      "HELOO SEE PERSONAL MESSAGE Type must support comparison operators.");
	return a <= b ? b : a;
}

struct customFail
{
	int value;
};
