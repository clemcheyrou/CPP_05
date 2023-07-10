/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:40:02 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 14:20:58 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _grade_signed(150), _grade_exec(150), _signed(false)
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

Form::Form(std::string name, int grade_signed, int grade_exec) : _name(name), _grade_signed(grade_signed), _grade_exec(grade_exec), _signed(false)
{
	if (_grade_signed< 1)
		throw GradeTooHighException();
	if (_grade_signed > 150)
		throw GradeTooLowException();
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

Form::Form( Form const &copy ) : _grade_signed(copy._grade_signed), _grade_exec(copy._grade_exec)
{
	_name = copy._name;
	_signed = copy._signed;
}

Form::~Form()
{
	std::cout << RED "Destructor" CLOSE " called" << std::endl;	
	return;
}

Form& Form::operator=( Form const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_signed = rhs._signed;
	}
	return(*this);
}

std::string Form::getName() const
{
	return(_name);
}

int Form::getGradeSigned() const
{
	return(_grade_signed);
}

int Form::getGradeExec() const
{
	return(_grade_exec);
}

bool Form::getSigned() const
{
	return(_signed);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_grade_signed > bureaucrat.getGrade())
	{
		std::cout << bureaucrat.getName() << " can signed" << std::endl;
		_signed = true;
	}
	else
		throw GradeTooLowException();	
}

std::ostream &operator<<( std::ostream &flux, Form const& form)
{
	flux << "Form name : "<< form.getName();
	flux << "\nGrade necessary to sign : " << form.getGradeSigned();
	flux << "\nGrade necessary to execute : " << form.getGradeExec();
	flux << "\n0 if not signed - 1 if signed : " << form.getSigned();
	return(flux);
}