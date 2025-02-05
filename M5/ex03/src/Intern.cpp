/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:41:42 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/21 14:04:47 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {std::cout<< CYAN "Intern default constructor" RESET <<std::endl; }

Intern::Intern(const Intern& other) {
	*this = other;
	std::cout<< MAGENTA "Intern copy constructor" RESET 
	<<" there are currently no resources to copy over"<<std::endl;
}

Intern& Intern::operator=(const Intern& other ){
	if (this != &other)
		std::cout<< " there are currently no resources to assign"<<std::endl;	
	return *this;
}

AForm* Intern::makeForm(std::string form, std::string target) {
	int x = 0;
	std::string forms[] = {
	"robotomy request",
	"presidential request",
	"shrubbery creation"	
	};
	while (x < 3)
	{
		if (x < 2 && forms[x] == form)
			break;
		x++;
	}
	switch (x)
	{
		case 3:
			break;
		//std::cout<<"intern creates "<<form<<" form"<<std::endl;
		case 0:
			return new RobotomyRequestForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
	default:
		break;
	}
	std::cerr<<"no such form to create \n";
	return nullptr;
}

Intern::~Intern() {std::cout<< RED "Intern destructor" RESET <<std::endl; }