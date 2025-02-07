/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:26:12 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 16:03:37 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm{} {
	std::cout<<CYAN "Default Constructor called for " RESET <<"PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm{"PresidentialPardonForm", target, 25, 5} {
	std::cout<<CYAN "Constructor called for " RESET <<"PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other) {
	std::cout<<CYAN "Copy Constructor called for " RESET <<"PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () {
	std::cout<<getName()<< RED " destroyed" RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::cout<< getTarget()<<" has been pardoned by Zaphod Beeblebrox \n";
}
