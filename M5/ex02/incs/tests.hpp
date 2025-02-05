/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 17:41:26 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	testInitilization(Bureaucrat& test);
void	testIncrement(Bureaucrat& test, int flag);
void	showWorking(Bureaucrat& test, int flag);
void	runBtests();

//ShrubberyCreationForm:

void	testinitilizationShrubbery();
void	testinitilizationRobot();
void	testinitilizationPresident();

void	testUnsignableShrubbery();
void	testUnsignableRobot();
void	testUnsignablePresident();

void	showWorkingShrubbery();
void	showWorkingRobot();
void	showWorkingPresident();

void	Shrubberry_tests();
void	Robot_tests();
void	President_tests();

