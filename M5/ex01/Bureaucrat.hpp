/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:20 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/06 13:27:18 by araveala         ###   ########.fr       */
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
 * @brief Nested exception classes already come with their own virtual destrcutors
 * therefore , the only useful reason for them to have 1, is if we must cleanup 
 * eg, dynamically alloacted data.
 * 
 * Here we have added forward decleration "class Form;", instead of inclusion of "Form.hpp".
 * This hastens compilation time due to not having to read through the header file during compile.
 * Now the signForm will only utalize what it needs
 * 
 * @note For this project i am changing value of a const string just to give clarity for testing.
 * Otherwise the chosen aternaitive would be to add a boolean if expression (if copy) was required
 * to indicate if object is a copy or not.
 * 
 * 
 */
class Form;
class Bureaucrat
{
	private:
		int		m_grade;
		const	std::string m_name;	

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);

		const	std::string getName() const;
		int		getGrade() const;

		void	setGrade(int value);
		
		void	increaseGrade();
		void	decreaseGrade();
		
		void	signForm(Form& Form);
		class	GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string context = "");
		};
		class	GradeTooLowException : public std::runtime_error {
			public:	
				GradeTooLowException(const std::string context = "");
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& target);