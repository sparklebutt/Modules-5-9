/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:31:57 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/04 10:29:31 by shaboom          ###   ########.fr       */
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
	std::cout<<"found false \n";
	return 0;
}
int main()
{
	// this is a scope box
	{
		std::vector<int> vec = {1, 2, 3, 4};
		::showDeets(vec);
		std::pair<bool, std::vector<int>::iterator> res1 = easyfind(vec, 2);
		if (pBool(res1.first) == 1)
			*res1.second = 100;
		::showDeets(vec);
		
	}
	{
		std::list<int> lst = {100, 200, 300, 400};
		::showDeets(lst);
		std::pair<bool, std::list<int>::iterator> res1 = easyfind(lst, 200);
		if (pBool(res1.first) == 1)
			*res1.second = 1;
		::showDeets(lst);
	}
	{
		// mess around with the order and it gets ordered for u
		std::unordered_map<int, std::string> aunordered_map = {{100, "one hundies"}, {200, "two hundies"}, {300, "three hundies"}, {400, "four hundies"}};
		::showDeets(aunordered_map);
		std::pair<bool, std::unordered_map<int, std::string>::iterator> res1 = easyfind(aunordered_map, 200);
		if (pBool(res1.first) == 1)
			res1.second->second = "keys are imutable , strings are not ";
		::showDeets(aunordered_map);
	}

	{
		std::unordered_map<int, std::string> bunordered_map = {{200, "two hundies"}, {100, "one hundies"}, {400, "four hundies"}, {300, "three hundies"}};
		::showDeets(bunordered_map);
		std::pair<bool, std::unordered_map<int, std::string>::iterator> res1 = easyfind(bunordered_map, 200);
		if (pBool(res1.first) == 1)
			res1.second->second = "keys are imutable , strings are not ";
		::showDeets(bunordered_map);
	}
	
}