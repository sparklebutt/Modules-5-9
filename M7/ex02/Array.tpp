/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:32 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/24 11:47:06 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_elements(nullptr), m_elementCount(0){
	std::cout<<"default constructor called \n";
}

template <typename T>
Array<T>::Array(unsigned int n) : m_elements(nullptr), m_elementCount(0){
	std::cout<<"constructor called \n";
	if (n > 0)
	{
		m_elements = new T[n];
		m_elementCount = n;
		//w *this.m_elements[other.elementCount];
	}
}

template <typename T>
Array<T>::Array(const Array &other) : Array() {
	if (other.m_elementCount > 0)
	{
		m_elements = new T[other.m_elementCount];
		//w *this.m_elements[other.elementCount];		
		for (std::size_t i = 0; i < other.m_elementCount; i++)
			m_elements[i] = other.m_elements[i];
	}
	m_elementCount = other.m_elementCount;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other)
	{
		if (*this.m_elements != nullptr)
			delete [] *this.m_elements;
		if (other.m_elementCount > 0)
		{
			m_elements = new T[other.elementCount];
			//w *this.m_elements[other.elementCount];		
			for (std::size_t i = 0; i < other.m_elementCount; i++)
				m_elements[i] = other.m_elements[i];
		}
		else
		{
			m_elements = nullptr;
			m_elementCount = 0;			
		}
		m_elementCount = other.m_elementCount;	
	}	
	return *this;
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
	if (index >= m_elementCount)
		throw std::runtime_error("out of range ");
	return m_elements[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const 
{
	if (index >= m_elementCount)
		throw std::runtime_error("out of range ");
	return m_elements[index];
}

template <typename T>
std::size_t Array<T>::getSize() const {
	return m_elementCount;
}

template <typename T>
Array<T>::~Array() {
	std::cout<<"deconstructor called\n";
	//if (m_elements != nullptr)
	delete [] m_elements;
}
