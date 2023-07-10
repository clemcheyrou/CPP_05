/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:25 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/23 12:03:40 by ccheyrou         ###   ########.fr       */
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

void Bureaucrat::signForm(AForm const &form) const
{
	if (form.getSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << "couldn't sign" << form.getName() << "because" << std::endl; 
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream &operator<<( std::ostream &flux, Bureaucrat const& bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " 
	<< bureaucrat.getGrade() << ".";
	return(flux);
}