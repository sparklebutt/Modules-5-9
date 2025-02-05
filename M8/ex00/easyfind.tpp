/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:05:24 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/04 10:29:31 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "easyfind.hpp"

/**
 * @brief 
 * 
 * the T::iterator will be different based on different inputs so we can not really define what type
 * it will be.
 * 
 * constexpr keyword tells compiler to resolve if expression on compile
 * 
 * is_unordered_map , a template that defaults to false , it is resolved on compile due to the use of constexpr and will
 * see from calling functions and compare to other templates to see which one matches and switch
 * to true.
 * @tparam T placeholder?
 * @param container the conatiner of any type
 * @param x the int to find
 * @return std::pair<bool, typename T::iterator> combining 2 return types into one usefull
 * for splitting up tasks based on returns values 
 */
template <typename T>
std::pair<bool, typename T::iterator> easyfind(T& container, int x) {

	typename T::iterator it;
	if constexpr (is_unordered_map<T>::value)
	    it = container.find(x);
	else
		it = std::find(container.begin(), container.end(), x);
	if (it != container.end())
		return std::make_pair(true, it); 
	return std::make_pair(false, container.end());
};


template <typename T>
void showDeets(T& container) {
	std::size_t size = 0;
	if constexpr (is_unordered_map<T>::value)
	{
        for (typename T::iterator element = container.begin(); element != container.end(); ++element)
			std::cout<<" element("<<++size<<") = "<<element->first<<"and "<<element->second<<"\n";
	}
	else
		for (typename T ::const_iterator element = container.begin(); element != container.end(); ++element) 
			std::cout<<" element("<<++size<<") = "<<*element<<"\n";	
}