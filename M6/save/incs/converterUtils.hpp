/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:06:15 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/22 15:22:48 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScalarConverter.hpp"

void	convertChar(std::string convertee);
void	convertNum(std::string convertee); //int?
void	convertDouble(std::string convertee);
void	convertFloat(std::string convertee);

void	handleSpecialInput(std::string convertee);
int		establishInput(std::string convertee);