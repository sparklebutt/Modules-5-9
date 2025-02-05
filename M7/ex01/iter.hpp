/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:51 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/23 15:06:31 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>
/**
 * @brief why &&func??
 * 
 * @tparam T 
 * @param array 
 * @param arrayLength 
 * @param func 
 */
template <typename T, typename Func>
void iter(T (&array)[5], std::size_t arrayLength, Func func ){
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