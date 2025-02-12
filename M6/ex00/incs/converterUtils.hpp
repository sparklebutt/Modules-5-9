/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converterUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:06:15 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/12 16:03:37 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScalarConverter.hpp"



void	convertChar(std::string convertee);

void	convertNum(std::string convertee);
void	convertDouble(std::string convertee);
void	convertFloat(std::string convertee);

void	handleSpecialInput(std::string convertee);
int		establishInput(std::string convertee);

void	handleDisplayValidation(int value);
void	handleDisplayValidation(double value);
void	handleDisplayValidation(float value);