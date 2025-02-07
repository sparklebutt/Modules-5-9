/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 15:05:14 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**
 * @example valid form request syntax
 * 	"robotomy request",
	"presidential request",
	"shrubbery creation"
 */

const  std::string formType = "robotomy request";
const std::string name = "bender";


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

void	Shrubbery_tests();
void	Robot_tests();
void	President_tests();
void	Intern_tests();
