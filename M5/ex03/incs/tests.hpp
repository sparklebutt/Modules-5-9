/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/21 13:49:20 by shaboom          ###   ########.fr       */
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
void	testinitilizationIntern();

void	testUnsignableShrubbery();
void	testUnsignableRobot();
void	testUnsignablePresident();
void	testUnsignableintern();

void	showWorkingShrubbery();
void	showWorkingRobot();
void	showWorkingPresident();
void	showWorkingIntern();

void	Shrubberry_tests();
void	Robot_tests();
void	President_tests();
void	Intern_tests();
