/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:45 by araveala          #+#    #+#             */
/*   Updated: 2025/04/16 18:40:14 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>{

	public:
		MutantStack() {};
		~MutantStack() {};
		using iterator = typename std::stack<T>::container_type::iterator;
		iterator begin() { return this->c.begin();};
		iterator end() { return this->c.end(); };
};

		/*void push(int x) { _theStack.push(x);};
		int top() {return _theStack.top();};
		void pop() { _theStack.pop(); };
		int size() { return _theStack.size(); };

		int begin() { return _theStack._get_container_.begin();};
		int end() { return _theStack.size(); };*/

		/*
		
		/*void push(int x) { this->c.push(x);};
		int top() {return this->top();};
		void pop() { this->pop(); };
		int size() { return this->size(); };
		*/