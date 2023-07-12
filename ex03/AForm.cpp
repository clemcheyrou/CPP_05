/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:40:02 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:46:20 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade_signed(150), _grade_exec(150), _signed(false)
{
	std::cout << GREEN "Constructor AForm" CLOSE " called" << std::endl;
	return ;
}

AForm::AForm(std::string name, const int grade_signed, const int grade_exec) : _name(name), _grade_signed(grade_signed), _grade_exec(grade_exec), _signed(false)
{
	if (_grade_signed< 1)
		throw GradeTooHighException();
	if (_grade_signed > 150)
		throw GradeTooLowException();
	std::cout << GREEN "Constructor AForm" CLOSE " called" << std::endl;
	return ;
}

AForm::~AForm()
{
	std::cout << RED "Destructor AForm" CLOSE " called" << std::endl;	
	return ;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _grade_signed(copy._grade_signed), _grade_exec(copy._grade_exec)
{
	_signed = copy._signed;
}

AForm& AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeSigned() const
{
	return (_grade_signed);
}

int AForm::getGradeExec() const
{
	return (_grade_exec);
}

bool AForm::getSigned() const
{
	return (_signed);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_grade_signed > bureaucrat.getGrade())
	{
		std::cout << bureaucrat.getName() << " can signed" << std::endl;
		_signed = true;
	}
	else
		throw GradeTooLowException();	
}

std::ostream &operator<<( std::ostream &flux, AForm const& form)
{
	flux << "Form name : "<< form.getName();
	flux << "\nGrade necessary to sign : " << form.getGradeSigned();
	flux << "\nGrade necessary to execute : " << form.getGradeExec();
	flux << "\n0 if not signed - 1 if signed : " << form.getSigned();
	return (flux);
}
