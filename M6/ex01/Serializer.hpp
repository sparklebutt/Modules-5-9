/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:31 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 18:38:31 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//#include <cmath>
#include <cstdint>
#include "data.hpp"
#include <iostream>

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