/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:28 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/17 14:32:49 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	testInitilization(Bureaucrat& test);
void	testIncrement(Bureaucrat& test, int flag);
void	showWorking(Bureaucrat& test, int flag);
void	runBtests();

void testUnsignable();
void testinitilization2();
void runAtests();
void showWorking2();