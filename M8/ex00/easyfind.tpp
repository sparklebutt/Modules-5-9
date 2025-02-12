/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:05:24 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/11 13:44:10 by araveala         ###   ########.fr       */
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
 * constexpr keyword tells compiler to resolve the statment on compile 
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


/**
 * Associative containers use a key - value storage system, this means that elements are handled using the key, 
 * eg key = phone number, value = name. Non-Associative containers access elements by order of element eg 1st, 2nd, 3rd.
 */
// Custom type_trait is set to false, this is used to check if contianer is associative
template <typename T, typename = void>
struct associative_container : std::false_type {};

// Switching associative contianer to true if typename matches key_type and mapped_type
template <typename T>
struct associative_container<T, std::void_t<typename T::key_type, typename T::mapped_type>> : std::true_type {};

template <typename T>
std::pair<bool, typename T::iterator> easyfind(T& container, int x) {

	// create a pointer to type T, that is defined to be an iterator 
	// how does it know type of contianer?
	typename T::iterator it;
	// handling associative containers, true?
	if constexpr (associative_container<T>::value)
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
	if constexpr  (associative_container<T>::value)
	{
        for (typename T::iterator element = container.begin(); element != container.end(); ++element)
			std::cout<<" element("<<++size<<") = "<<element->first<<"and "<<element->second<<"\n";
	}
	else
		for (typename T ::const_iterator element = container.begin(); element != container.end(); ++element) 
			std::cout<<" element("<<++size<<") = "<<*element<<"\n";	
}