/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:31 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 14:22:46 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdint>
#include "data.hpp"
#include <iostream>

/**
 * uintptr_t is a unsigned int , however it gurantees to have enough space to 
 * hold a pointer. This process should involve far larger data sets for multiple reasons.
 * Types of data that would be stored in this data struct for example, endianness, 
 * the archtecture where packaged, data types and so forth. 
 * 
 * When deserializing , you would do multiple checks to adjust for different architectures,
 * permissions/rights and so forth. For example if the endianness differs we would adjust byte order,
 * checks to see what adjustmenets might need to made based on architecture, (data might need
 * to be handled in smaller sections or choices might need to be made with percision).
 */
class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &other) = delete;
		Serializer operator=(Serializer &other) = delete;
		~Serializer();
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};