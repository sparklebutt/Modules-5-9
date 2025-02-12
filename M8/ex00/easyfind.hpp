/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:59:06 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/11 13:41:11 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>  // For std::find
#include <exception>
#include <utility>

#include <list> //
#include <unordered_map>
#include <type_traits>

template <typename T>
std::pair<bool, typename T::iterator> easyfind(T& container, int x);

template <typename T>
void showDeets(T& container);

template <typename T>
struct is_unordered_map : std::false_type {};

template <typename Key, typename Value, typename Compare, typename Allocator>
struct is_unordered_map<std::unordered_map<Key, Value, Compare, Allocator>> : std::true_type {};

template <typename Key, typename Value, typename Hash, typename KeyEqual, typename Allocator>
struct is_unordered_map<std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>> : std::true_type {};
#include "easyfind.tpp"