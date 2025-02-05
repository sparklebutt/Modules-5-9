/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:30:04 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 18:54:06 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief de
 * Data is a pointer so it must be dereferenced on next print of address
 * 
 * @return int 
 */
int	main()
{
	Data miniData = {69, "yo mama"};

	std::cout<<"original data address "<<&miniData<<std::endl;
	std::cout<<"original data address "<<miniData.number<<std::endl;
	std::cout<<"original data address "<<miniData.name<<std::endl;

	uintptr_t raw = Serializer::serialize(&miniData);
	
	std::cout<<"what is in raw (serialized) "<<raw<<std::endl;
	
	Data* deData = Serializer::deserialize(raw);
	std::cout<<"what is in deData (deserialized) "<<raw<<std::endl;

	std::cout<<"new data address "<<deData<<std::endl;
	std::cout<<"new data address "<<deData->number<<std::endl;
	std::cout<<"new data address "<<deData->name<<std::endl;
	
	return 0;
}