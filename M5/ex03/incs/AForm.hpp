/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/16 17:45:38 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

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
 * AForm has been made abstract with the use of virtual void execute() = 0, this ensure thats derived classes
 * must utalize their own implementation.  
 */
class AForm
{
	private:
		const std::string m_name;
		const std::string m_target;
		const int m_gradeToSign;
		const int m_gradeToExec;
		bool m_isSigned;
	public:
		AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		AForm(const std::string name, std::string target, int gradeToSign, int gradeToExec);

		const std::string getName() const;
		const std::string getTarget() const;	
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getIsSigned() const;

		static int checkGrade(int grade);
		void beSigned(Bureaucrat& appraisee);

		virtual void execute(Bureaucrat const & executor) const = 0;
		void confirmExecution(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string context = "");
		};
		class GradeTooLowException : public std::runtime_error {
			public:	
				GradeTooLowException(const std::string context = "");
		};
		class FormNotSigned : public std::runtime_error {
			public:	
				FormNotSigned(const std::string context = "");
		};
};
std::ostream& operator<<(std::ostream& out, AForm& target);