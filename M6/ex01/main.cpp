/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:30:04 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/13 13:57:35 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief Serializing pointers allow for a more stable storage of pointer information
 * that can be deconstructed back to pointers later. 
 * 
 * @return int 
 */
int	main()
{
	Data miniData = {69, "yo mama"};

	std::cout<<"original data address "<<&miniData<<std::endl;
	std::cout<<"original data number "<<miniData.number<<std::endl;
	std::cout<<"original data name "<<miniData.name<<std::endl;

	uintptr_t raw = Serializer::serialize(&miniData);
	
	std::cout<<"what is in raw (serialized) "<<raw<<std::endl;
	
	Data* deData = Serializer::deserialize(raw);
	std::cout<<"what is in deData (deserialized) "<<deData<<std::endl;

	std::cout<<"new data address "<<deData<<std::endl;
	std::cout<<"new data address "<<deData->number<<std::endl;
	std::cout<<"new data address "<<deData->name<<std::endl;
	
	return 0;
}