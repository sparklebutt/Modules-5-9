/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:26:12 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 13:45:23 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm{} {
	std::cout<<CYAN "Default Constructor called for " RESET <<"RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm{"RobotomyRequestForm", target, 72, 55} {
	std::cout<<CYAN "Constructor called for " RESET <<"RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other) {
	std::cout<<CYAN "Copy Constructor called for " RESET <<"RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm () {
	std::cout<<getName()<< RED " destroyed" RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::cout<< getTarget()<<"prrrrrzrzrzrzrzrzrzrrzrz zzzziiiu zzziiiu, ppppprrrrrrrrt ziiiu\n";
	static bool toggle = false;
	//std::cout<<(rand() % 2)<<std::endl;
	//if (rand() % 2 == 0)
	if (toggle)
		std::cout<<getTarget()<< BLUE " has been robotomized \n" RESET;
	else
		std::cout<<getTarget()<< MAGENTA " robotomy unsuccsessfull \n" RESET;
	toggle = !toggle;
}
