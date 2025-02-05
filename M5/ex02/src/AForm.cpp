/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:29:45 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/16 17:35:11 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : m_name("DEFAULT"), m_target("DEFAULT"), m_gradeToSign(150), m_gradeToExec(150), m_isSigned(false) {
	std::cout<<CYAN "Constructor called for " RESET <<m_name<<std::endl;
}

/**
 * @brief Construct a new AForm:: AForm object
 * 
 * Using *this = other; within the copy constructor is actually not a good practice,
 * especially in this context with const members. Assignment Modifies an existing object
 * with data from another existing object, requiring checks for self-assignment and handling
 * of existing resources (e.g., dynamic memory).
 * A constructor should initilize a new object , utalizing data from an existing object.
 * This can lead to infinitae recursion, This is because the assignment operator might internally
 * call the copy constructor again, and vice versa, creating an endless loop.
 * 
 * isSIgned is set to false as this is construction, subject states during construction flag=false. 
 * @param other from which data is taken
 */
AForm::AForm(const AForm &other) 
	: m_name(other.m_name + "_Copy"),
	m_gradeToSign(other.m_gradeToSign),
	m_gradeToExec(other.m_gradeToExec),
	m_isSigned(false){
	std::cout<<CYAN "AFORM COPY Constructor called for " RESET <<m_name<<std::endl;
}

AForm::AForm(const std::string name, std::string target, int gradeToSign, int gradeToExec) 
	: m_name(name),
	m_target(target),
	m_gradeToSign(checkGrade(gradeToSign)),
	m_gradeToExec(checkGrade(gradeToExec)),
	m_isSigned(false) {
	std::cout<<CYAN "AForm Constructor called for " RESET <<m_name<<std::endl;
}

int AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooLowException("AForm:: checkGrade ");
	if (grade > 150)
		throw GradeTooHighException("AForm:: checkGrade ");
	return grade;
}
/**
 * @brief 
 * 
 * check that objects do not share the same address, 
 * assign others name with a copy marker for testing purposes only.
 * 
 * Considering that grades are defined as const and the assignment operator
 * will only chjeck for self assignment and give you the evaluator a clear copy name
 * to help follow the code output.
 *  
 * @param other from whcih to copy from 
 * @return AForm& as either changed or already correctly assigned
 */
AForm& AForm::operator=(const AForm &other) {
	if (this != &other)
	{
		std::string swapstr = other.m_name + "_assigned";
		std::swap(const_cast<std::string&>(m_name), const_cast<std::string&>(swapstr));
	}
	return *this;
}

AForm::~AForm() {
	std::cout<< RED "Deconstructor called for " RESET << m_name <<std::endl;
}

// GETTERS
const std::string AForm::getName() const{
return this->m_name;
}

const std::string AForm::getTarget() const{
return this->m_target;
}
int AForm::getGradeToSign() const {
	return this->m_gradeToSign;
}

int AForm::getGradeToExec() const {
	return this->m_gradeToExec;
}

bool AForm::getIsSigned() const {
	return this->m_isSigned;
}


void AForm::beSigned(Bureaucrat& appraisee) {
	if (appraisee.getGrade() > m_gradeToSign)
		throw GradeTooLowException(" couldnt sign " + m_name + " because :");
	m_isSigned = true;
}

void AForm::confirmExecution(Bureaucrat const & executor) const {
	if (getIsSigned() == 0)
		throw FormNotSigned();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	execute(executor);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string context)
	 : std::runtime_error(context.empty() ? RED "grade too high!" RESET : context + RED ": grade too high!" RESET)  {}
	 
AForm::GradeTooLowException::GradeTooLowException(const std::string context) 
	: std::runtime_error(context.empty() ? RED "grade too low!" RESET : context + RED ": grade too low!" RESET)  {}

AForm::FormNotSigned::FormNotSigned(const std::string context) 
	: std::runtime_error(context.empty() ? RED "form not signed!" RESET : context + RED ": form not signed!" RESET)  {}

std::ostream& operator<<(std::ostream& out, AForm& target) {
	if (target.getName() == "DEFAULT")
		std::cout<<RED "AForm is not set, giving defaults:: " RESET;
	return out<< YELLOW "AForm " RESET << target.getName() << "'s grade to sign is :(" 
	<< target.getGradeToSign() << ") grade to execute is :(" << target.getGradeToExec()
	<< ") AForm is signed = " << target.getIsSigned();
}