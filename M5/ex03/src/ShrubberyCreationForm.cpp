/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:26:12 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 13:45:23 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm{} {
	std::cout<<CYAN "Default Constructor called for " RESET <<"ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm{"ShrubberyCreationForm", target, 145, 137} {
	std::cout<<CYAN "Constructor called for " RESET <<"ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other) {
	std::cout<<CYAN "Copy Constructor called for " RESET <<"ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {
	std::cout<<getName()<< RED " destroyed" RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::ofstream outFile(getTarget() + "_shrubbery");
	if(outFile.is_open())
	{
		outFile<<"Root\n├── Folder1\n│   ├── File1.txt\n│   ├── File2.txt\n"
		<<"│   └── Subfolder1\n│       ├── File3.txt\n│       └── File4.txt\n"
		<<"└── Folder2\n├── File5.txt\n└── File6.txt\n";
	}
	else
		std::cerr<<"error occured on open"<<std::endl;
	outFile.close();
}
