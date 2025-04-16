/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:14:31 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 16:31:44 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef> 
#include <vector>
#include <stdexcept>
class Span 
{
	public:
		Span();
		Span(unsigned int n);		
		Span(Span &other) = delete;
		Span& operator=(Span &other) = delete;
		~Span();
		void addNumber(int num);
		
		template <typename Iterator>
    	void addRange(Iterator begin, Iterator end) {
        	if (begin == end)
				throw std::runtime_error("can not fill with empty :: ");
			if (std::distance(begin, end) > m_maxSize - static_cast<unsigned int>(m_array.size())) {
            	throw std::overflow_error("Cannot add more numbers, Span will exceed its maximum size.");
        	}
        	m_array.insert(m_array.end(), begin, end);
    	}
		
		int shortestSpan();
		int longestSpan();
		std::vector<int> sortem();

		
	    void showArray() const;
	private:
		unsigned int m_maxSize;
		std::vector<int> m_array;
};