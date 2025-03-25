/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:51 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/05 15:37:19 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#pragma once
/**
 * <array> is a fixed type and not dynamic therefore i am not breaking the rules
 * &array[N] N is deduced from the parameter we gave array on creation 
 */

/**
 * @brief why &&func??
 * 
 * @tparam T 
 * @param array 
 * @param arrayLength 
 * @param func 
 */

// simple array
template <typename T, std::size_t N, typename Func>
void iter(T (&array)[N], std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		array[i] = func(array[i]);
}
// ptr array
/*template <typename T, std::size_t N, typename Func>
void iter(T* (&array)[N], std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		*array[i] = func(*array[i]);
}

// multi dimensional simple array
template <typename T, std::size_t N, std::size_t X, typename Func>
void iter(T (&array)[N][X], std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		iter(array[i], N + 1, func);
}
// multi ptr array
template <typename T, std::size_t N, std::size_t X, typename Func>
void iter(T* (&array)[N][X], std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		iter(array[i], N + 1, func);
}

// std::array type 
template <typename T, std::size_t N, typename Func>
void iter( std::array<T, N>& array, std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		array[i] = func(array[i]);
}

template <typename T, std::size_t N, typename Func>
void iter( std::array<T*, N> array, std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		*array[i] = func(*array[i]); //this one y
}

// multi dimensional simple std::array type
template <typename T, std::size_t N, std::size_t X, typename Func>
void iter( std::array<std::array<T, X>, N>& array, std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		iter(array[i], N + 1, func);
}

template <typename T, std::size_t N, std::size_t X, typename Func>
void iter( std::array<std::array<T*, X>, N>& array, std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		iter(array[i], N + 1, func);
}*/

/**
 * @brief 
 *
 * testing instatiated templates 
 */
template <typename T>
T increment(T num) {
    return num + 10;
}

template <typename T>
T increment_plus(T num) {
    return num + 10;
}

/*template <typename T>
T increment(T* num) {
    return num + 10;
}*/
/*template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}*/
