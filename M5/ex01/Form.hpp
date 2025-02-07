/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/07 11:01:48 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

/**
 * @brief 
 * prevents circular depencies 
 * 
 */
class Bureaucrat;

/**
 * @brief nested exception classes already come with thier own virtual destrcutors
 * therefore , the only useful reason for them to have 1, is if we must cleanup 
 * eg, dynamically alloacted data.
 * 
 * @note For this project i am changing value of a const string just to give clarity for testing.
 * Otherwise the chosen alternative would be to add a boolean if expression (if copy) was required
 * to indicate if object is a copy or not.
 * 
 */
class	Form
{
	private:
		const	std::string m_name;
		const	int m_gradeToSign;
		const	int m_gradeToExec;
		bool	m_isSigned;

	public:
		Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		Form(const std::string name, int gradeToSign, int gradeToExec);

		const	std::string getName() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		bool	getIsSigned() const;
		void	beSigned(Bureaucrat& appraisee);
		
		static int checkGrade(int grade);
		using GradeTooHighException = Bureaucrat::GradeTooHighException;
		using GradeTooLowException = Bureaucrat::GradeTooLowException;		
};

std::ostream& operator<<(std::ostream& out, Form& target);

/**
 * @example As bureaucrat already has example below, utaliizing the using keyword
 * allows for my code to be cleaner and more readable. 
 *class	GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string context = "");
		};
		class	GradeTooLowException : public std::runtime_error {
			public:	
				GradeTooLowException(const std::string context = "");
}; 
 */
