/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/06 12:13:12 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>
//#include <array>
template <typename T>
class Array 
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const ;
		unsigned int getSize() const;
		~Array();

	private:
		// this is where we store the array 
		T *m_elements;
		unsigned int m_elementCount;
};
#include "Array.tpp"