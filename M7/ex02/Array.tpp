/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:11:32 by shaboom           #+#    #+#             */
/*   Updated: 2025/03/06 12:48:24 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Array.hpp"

/**
 * instantiation of a class automatically allocates to stack, initializing a ptr to nullptr, means that accessing that 
 * pointer is accessing allocated memeory, unitialized however, we would potentially
 * be accessing non-allocated data. 
 */
// programme must never access non allocated memory must i allocate here too 
template <typename T>
Array<T>::Array() : m_elements(nullptr), m_elementCount(0){ }

//se daultf here to cover all te ground
template <typename T>
Array<T>::Array(unsigned int n) : m_elements(nullptr), m_elementCount(n){
	//std::cout<<"constructor called "<<n<<"\n";
// do i need this check? because we nullptr
	if (n == 0)
	{
		std::cout<<"eek"<<std::endl;
	}
	else
	{
		m_elements = new T[n];
		m_elementCount = n;
		for (unsigned int i = 0; i < n; i++)
		{
			m_elements[i] = 0;
			//std::cout<<"elem val at "<<i<<" "<<m_elements[i]<<std::endl;			
		}
		//w *this.m_elements[other.elementCount];
	}
}

template <typename T>
Array<T>::Array(const Array &other) : Array() {
	if (other.m_elementCount > 0)
	{
		m_elements = new T[other.m_elementCount];
		//w *this.m_elements[other.elementCount];		
		for (unsigned int i = 0; i < other.m_elementCount; i++)
		{
			m_elements[i] = other.m_elements[i];			
		}

	}
	m_elementCount = other.m_elementCount;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other)
	{
		if (*this != nullptr)
			delete [] *this;
		if (other.m_elementCount > 0)
		{
			m_elements = new T[other.elementCount];
			//w *this.m_elements[other.elementCount];		
			for (unsigned int i = 0; i < other.m_elementCount; i++)
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
T& Array<T>::operator[](unsigned int index)
{
	if (index >= m_elementCount)
		throw std::runtime_error("out of range ");
	return m_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const 
{
	//std::cout<<"what is index "<<index<<std::endl;
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
	//if (m_elements != nullptr)
	delete [] m_elements;
}
