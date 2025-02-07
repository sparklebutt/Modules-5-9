/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:41:42 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 14:57:55 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <memory>
Intern::Intern() { std::cout<< CYAN "Intern default constructor" RESET <<std::endl; }

Intern::Intern(const Intern& other) {
	*this = other;
	std::cout<< MAGENTA "Intern copy constructor" RESET 
	<<" there are currently no resources to copy over"<<std::endl;
}

Intern& Intern::operator=(const Intern& other ) {
	if (this != &other)
		std::cout<< " there are currently no resources to assign"<<std::endl;	
	return *this;
}
/**
 * 
 */
	 
AForm* Intern::makeForm(std::string form, std::string target) {
	int x = 0;
	std::string forms[4] = {
	"robotomy request",
	"presidential request",
	"shrubbery creation",
	"test",
	};
	while (x < 3)
	{
		if (forms[x] == form)
			break;
		x++;
	}
	
	switch (x)
	{
		case 0:
			return new RobotomyRequestForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		case 3:
			throw std::runtime_error("oh dear, you will have to go and see a vogan about this no such form as (" + form + ") refer to The Vogon Constructor Fleet");
	default:
			throw std::runtime_error(" unique error unknown:: intern.cpp:: line 55");
	}
}


/*Intern::NoRequestForm::NoRequestForm(std::string form) 
	: std::runtime_error(form.empty() ? RED "form needs a name " : RED "no such form as" + form RESET)  {}*/

Intern::~Intern() { std::cout<< RED "Intern destructor" RESET <<std::endl; }