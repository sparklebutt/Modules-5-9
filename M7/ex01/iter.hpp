/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:51 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 11:50:39 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
//#include <string>
/**
 * @brief why &&func??
 * 
 * @tparam T 
 * @param array 
 * @param arrayLength 
 * @param func 
 */
template <typename T, std::size_t N, typename Func>
void iter(T (&array)[N], std::size_t arrayLength, Func func ){
	for (std::size_t i = 0; i < arrayLength; i++)
		array[i] = func(array[i]);
}

/**
 * @brief 
 *
 * testing instatiated templates 
 */
template <typename T>
T increment(T num) {
    return num + 10;
}