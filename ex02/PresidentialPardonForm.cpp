/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:57:59 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:45:18 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential",25,5), _target("default")
{
	std::cout << GREEN "Constructor PresidentialPardonForm" CLOSE " called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential",25, 5) , _target(target)
{
	std::cout << GREEN "Constructor PresidentialPardonForm" CLOSE " called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &copy ) : AForm(copy._name, copy._grade_signed, copy._grade_exec)
{
	if (this != &copy)
		_signed = copy._signed;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED "Destructor PresidentialPardonForm" CLOSE " called" << std::endl;	
	return ;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < _grade_signed && _signed == true )
	{
		std::cout << executor.getName() << ": ";
		std::cout << _target << " forgive by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw GradeTooLowException();	
	return ;	
}