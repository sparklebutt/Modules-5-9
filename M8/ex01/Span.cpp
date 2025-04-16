/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:14:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 17:03:16 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>

Span::Span() : m_maxSize(0) {
	std::cout<<"defaulty constructor called \n";
}

Span::Span(unsigned int n) : m_maxSize(n) {
	if (m_maxSize > 0)
		m_array.reserve(m_maxSize);
	std::cout<<" constructor called \n";
}

Span::~Span(){
	std::cout<<" destructor called \n";
}

void Span::addNumber(int num) {
	if (m_array.size() >= m_maxSize)
		throw std::runtime_error("we have reached capacity:: ");
	m_array.push_back(num);
}

std::vector<int> Span::sortem()
{
	if (m_array.size() < 2)
		throw std::runtime_error("not enough elements");
	std::vector<int> sorted(m_array);
	std::sort(sorted.begin(), sorted.end());
	return sorted;
}
void Span::showArray() const {
    for (int number : m_array) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}


int Span::shortestSpan() {
	std::vector<int> sorted(sortem());
	int minum = std::numeric_limits<int>::max();
	for (unsigned int i = 1; i < sorted.size(); ++i)
	{
		int comp = sorted[i] - sorted[i - 1];
		if (comp < minum)
			minum = comp;
	}	
	return minum;
}

int Span::longestSpan() {
	std::vector<int> sorted(sortem());
	return sorted.back() - sorted.front();
}
