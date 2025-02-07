/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 11:27:52 by araveala         ###   ########.fr       */
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

void	Shrubbery_tests();
void	Robot_tests();
void	President_tests();

