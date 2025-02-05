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
 * @note If we had more freedoms for this project i would have added a 3rd private memeber
 * . A boolean to indicate if said object is a copy or not, instead of changing the const
 * string to have "_copy". This is just for clarity for you the evaluator .
 * 
 */
class AForm
{
	private:
		const std::string m_name;
		// grade bureaucrat must match to sign AForm
		const int m_gradeToSign;
		// grade bureaucrat must match to execute AForm?
		const int m_gradeToExec;
		// has this AForm been signed
		bool m_isSigned;

	public:
		AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		~AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExec);

		const std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getIsSigned() const;

		static int checkGrade(int grade);
		void beSigned(Bureaucrat& appraisee);
		class GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string context = "");
		};
		class GradeTooLowException : public std::runtime_error {
			public:	
				GradeTooLowException(const std::string context = "");
		};
};

std::ostream& operator<<(std::ostream& out, AForm& target);