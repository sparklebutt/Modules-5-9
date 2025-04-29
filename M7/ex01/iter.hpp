/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:51 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 13:52:40 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

/**
 * @brief 
 * 
 * These template functions take an address to an array , an array length
 * and the function that will be called on each element.
 * @param array 
 * @param arrayLength 
 * @param func 
 */

// This iter handles simple arrays
template <typename T, typename Func>
void iter(T *array, std::size_t arrayLength, Func func) {
	for (std::size_t i = 0; i < arrayLength; i++)
		func(array[i]);
}

// this iter handles multi dimensional arrays 
template <typename T, std::size_t N, std::size_t X, typename Func>
void iter(T (&array)[N][X], std::size_t arrayLength, Func func){
	for (std::size_t i = 0; i < arrayLength; i++) {
		iter(array[i], X, func);
	}
}
/**
 * @brief 
 *
 * testing instatiated templates 
 */
template <typename T>
void increment_value(T &num) {
	num += 10;
}

template <typename T>
T show_const(T const constValue) {
	std::cout<<"this value is = "<<constValue<<std::endl;	
	return constValue;
}
