/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/24 11:13:04 by shaboom          ###   ########.fr       */
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
		T& operator[](std::size_t index);
		const T& operator[](std::size_t index) const ;
		std::size_t getSize() const;
		~Array();

	private:
		// this is where we store the array 
		T *m_elements;
		std::size_t m_elementCount;
};
#include "Array.tpp"