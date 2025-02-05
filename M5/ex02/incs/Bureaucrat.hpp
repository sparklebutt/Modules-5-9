/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 12:16:30 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
//#include "PresidentialPardonForm.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
/**
 * @brief nested exception classes already come with thier own virtual destrcutors
 * therefore , the only useful reason for them to have 1, is if we must cleanup 
 * eg, dynamically alloacted data.
 * 
 * @note If we had more freedoms for this project i would have added a 3rd private memeber
 * . A boolean to indicate if said object is a copy or not, instead of changing the const
 * string to have "_copy". This is just for clarity for you the evaluator .
 * 
 */
class AForm;
//class PresidentialPardonForm;

class Bureaucrat
{
	private:
		int m_grade;
		const std::string m_name;	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);

		const std::string getName() const;
		int getGrade() const;
	//testing helper
		void setGrade(int value);
		
		void increaseGrade();
		void decreaseGrade();
		
		void signAForm(AForm& AForm);
		void executeForm(AForm const & form);
		
		class GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string context = "");
		};
		class GradeTooLowException : public std::runtime_error {
			public:	
				GradeTooLowException(const std::string context = "");
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& target);