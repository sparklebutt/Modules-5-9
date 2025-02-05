/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:20:18 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/20 12:55:53 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
/**
 * @brief inheriting public Aform is correct, since we will be only doing single
 * line inheritance we do not need to worry about the diamond problem, however it could
 * be protective to inherit virtually . 
 * 
 */
class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm ();
		PresidentialPardonForm (std::string target);
		PresidentialPardonForm (const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm ();
		void execute(Bureaucrat const & executor) const override;

};