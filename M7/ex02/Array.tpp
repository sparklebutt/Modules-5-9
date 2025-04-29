/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:32 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:15 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Array.hpp"
#include <type_traits>

template <typename T>
Array<T>::Array() : m_elements(new T[0]), m_elementCount(0) {}

template <typename T>
Array<T>::Array(unsigned int n): m_elements(new T[n]), m_elementCount(n) {		
	for (unsigned int i = 0; i < m_elementCount; i++)
		m_elements[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &other) {
	m_elements = nullptr;
	m_elements = new T[other.m_elementCount];
	for (unsigned int i = 0; i < other.m_elementCount; i++) {
		m_elements[i] = other.m_elements[i];			
	}
	m_elementCount = other.m_elementCount;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete [] *this;
		m_elements = nullptr;
		m_elements = new T[other.elementCount];	
		for (unsigned int i = 0; i < other.m_elementCount; i++)
			m_elements[i] = other.m_elements[i];
		m_elementCount = other.m_elementCount;	
	}	
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= m_elementCount)
		throw std::runtime_error("out of range ");
	return m_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index > m_elementCount)
		throw std::runtime_error("out of range ");
	return m_elements[index];
}

template <typename T>
unsigned int Array<T>::getSize() const {
	return m_elementCount;
}

template <typename T>
Array<T>::~Array() {
	std::cout<<"deconstructor called\n";
	delete [] m_elements;
}
