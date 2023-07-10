/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 14:06:17 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0)
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED "Destructor" CLOSE " called" << std::endl;	
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy )
{
	_name = copy._name;
	_grade= copy._grade;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

int Bureaucrat::incrementGrade()
{
	_grade += 1;
	if (_grade > 150)
		throw GradeTooLowException();
	return(_grade);
}

int Bureaucrat::decrementGrade()
{
	_grade -= 1;
	if (_grade < 1)
		throw GradeTooHighException();
	return(_grade);
}

void Bureaucrat::signForm(Form const &form) const
{
	if (form.getSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << "couldn't sign" << form.getName() << "because" << std::endl; 
}

std::ostream &operator<<( std::ostream &flux, Bureaucrat const& bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " 
	<< bureaucrat.getGrade() << ".";
	return(flux);
}