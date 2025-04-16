/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:31:57 by shaboom           #+#    #+#             */
/*   Updated: 2025/04/16 14:55:03 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector> //

int pBool(bool show)
{
	if (show == 1)
	{
		std::cout<<"found true \n";
		return 1;		
	}
	std::cerr<<"found false \n";
	return 0;
}

int main()
{
	// Here i show how i would handle errors
	{
		std::vector<int> vec = {0, 0, 0, 0};
		::showDeets(vec);
		std::pair<bool, std::vector<int>::iterator> res1 = easyfind(vec, 2);
		if (res1.first == 0)
			std::cerr<<"ERROR:: handle error value not found \n";
		else if (res1.first == 1) {
			*res1.second = 100;						
			::showDeets(vec);
		}
		std::cout<<"\n";
	}

	{
		std::vector<int> vec = {1, 3, 4, 2};
		::showDeets(vec);
		std::pair<bool, std::vector<int>::iterator> res1 = easyfind(vec, 2);
		if (pBool(res1.first) == 1)
			*res1.second = 100;
		::showDeets(vec);
		std::cout<<"\n";
	}
	{
		std::list<int> lst = {100, 200, 300, 400};
		::showDeets(lst);
		std::pair<bool, std::list<int>::iterator> res1 = easyfind(lst, 200);
		if (pBool(res1.first) == 1)
			*res1.second = 1;
		::showDeets(lst);
		std::cout<<"\n";
	}
	{
		// mess around with the order and it gets ordered for u
		std::unordered_map<int, std::string> aunordered_map = {{100, "one hundies"}, {200, "two hundies"}, {300, "three hundies"}, {400, "four hundies"}};
		::showDeets(aunordered_map);
		std::pair<bool, std::unordered_map<int, std::string>::iterator> res1 = easyfind(aunordered_map, 200);
		if (pBool(res1.first) == 1)
			res1.second->second = "keys are imutable , strings are not ";
		::showDeets(aunordered_map);
		std::cout<<"\n";
	}

	{
		std::unordered_map<int, std::string> bunordered_map = {{200, "two hundies"}, {100, "one hundies"}, {400, "four hundies"}, {300, "three hundies"}};
		::showDeets(bunordered_map);
		std::pair<bool, std::unordered_map<int, std::string>::iterator> res1 = easyfind(bunordered_map, 200);
		if (pBool(res1.first) == 1)
			res1.second->second = "keys are imutable , strings are not ";
		::showDeets(bunordered_map);
		std::cout<<"\n";
	}
	
}