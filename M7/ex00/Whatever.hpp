/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 13:50:30 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

/**
 * swap should not handle const as that requires circumnavigating constness which defeats the purpose of its existence
 */
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
T max(const T &a, const T &b) {
	return a <= b ? b : a;
};


