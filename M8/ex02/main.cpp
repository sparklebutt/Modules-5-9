/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:23:43 by araveala          #+#    #+#             */
/*   Updated: 2025/07/01 15:54:22 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void iteratorValues(MutantStack<int>& stack)
{
	stack.push(5);
	stack.push(17);
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << std::endl;
	stack.push(3);
	stack.push(5);
	stack.push(737);
	//[...]
	stack.push(0);
	
}

int main()
{

	MutantStack<int> mstack;
	/*mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);*/
	iteratorValues(mstack);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout<<"\n";
	std::stack<int> (lstack);
	{
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		//[...]
		lstack.push_back(0);
		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		return 0;
		
	}
	const MutantStack<int> const_mstack = mstack;
	
	//iteratorValues(const_mstack);
	{
		MutantStack<int>::const_iterator const_it = const_mstack.begin();
		MutantStack<int>::const_iterator const_ite = const_mstack.end();
		while (const_it != const_ite)
		{
			std::cout << *const_it << std::endl;
			++const_it;
		}
		
		
	}
}
/*
	std::stack test;

	
	return 0;
}*/