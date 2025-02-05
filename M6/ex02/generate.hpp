/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:54:39 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 19:55:31 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"

Base* generate();
void identify(Base* p);
//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden.