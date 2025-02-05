/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:29:45 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/16 17:35:11 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_grade(150), m_name("DEFAULT"){
	std::cout<<CYAN "Constructor called for " RESET <<m_name<<std::endl;
} // m_grade(0), m_name("steve") 

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name){

	std::cout<<CYAN "Constructor called for " RESET <<m_name<<std::endl;
	if (grade < 1)
		throw GradeTooLowException("thrown from parameterized constructor ");
	if (grade > 150)
		throw GradeTooHighException("thrown from parameterized constructor ");
	m_grade = grade;
	//std::swap(const_cast<std::string&>(m_name), const_cast<std::string&>(name));
	//m_name = name;
}

/**+
 * @brief 
 * 
 * check that objects do not share the same address, 
 * assign others name with a copy marker and assign others grade. 
 * @param other from whcih to copy from 
 * @return Bureaucrat& as either changed or already correctly assigned
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
	{
		std::string swapstr = other.m_name + "_copy";
		std::swap(const_cast<std::string&>(m_name), const_cast<std::string&>(swapstr));
		//this->m_name = other.m_name;//swapstr;//other.m_name + "_copy";
		this->m_grade = other.m_grade;

	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout<< RED "Deconstructor called for " RESET << m_name <<std::endl;
}

const std::string Bureaucrat::getName() const{

	return this->m_name;
}

int Bureaucrat::getGrade() const {

	return this->m_grade;
}

/**
 * @brief setter used for testing help
 *  
 */
void Bureaucrat::setGrade(int value) {

	this->m_grade = value;
}
/**
 * @brief Highest/most valuable grade is 1 increasing grade is will 
 * always be minus , decreasing grade will take the value down to max 
 * 150 and thus will be plus.
 * 
 */
void Bureaucrat::increaseGrade() {
	if (m_grade == 1)
		throw GradeTooHighException("bureucrat " + getName() + " grade already max, increasing will lead to ");
	m_grade--;
}
void Bureaucrat::decreaseGrade() {
	if (m_grade == 150)
		throw GradeTooLowException("bureucrat " + getName() + " grade already min, decreasing will lead to ");
	m_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string context)
	 : std::runtime_error(context.empty() ? RED "grade too high!" RESET : context + RED ": grade too high!" RESET)  {}
	 
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string context) 
	: std::runtime_error(context.empty() ? RED "grade too low!" RESET : context + RED ": grade too low!" RESET)  {}
	
std::ostream& operator<<(std::ostream& out, Bureaucrat& target) {
	if (target.getName() == "DEFAULT")
		std::cout<<RED "bureaucrat is not set, giving defaults:: " RESET;
	return out<< YELLOW "Bureaucrat " RESET << target.getName() << "'s grade is : " << target.getGrade();
}