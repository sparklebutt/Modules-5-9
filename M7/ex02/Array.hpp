/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/14 10:54:15 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>
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
		T *m_elements;
		unsigned int m_elementCount;
};
#include "Array.tpp"