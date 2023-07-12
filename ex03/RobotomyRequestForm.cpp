/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:04 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:15:10 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy",72,45), _target("default")
{
	std::cout << GREEN "Constructor RobotomyRequestForm " CLOSE "called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy",72,45) , _target(target)
{
	std::cout << GREEN "Constructor RobotomyRequestForm " CLOSE "called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &copy ) : AForm(copy._name, copy._grade_signed, copy._grade_exec)
{
	if (this != &copy)
		_signed = copy._signed;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED "Destructor RobotomyRequestForm" CLOSE " called" << std::endl;	
	return;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
		_signed = rhs._signed;
	return(*this);	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < _grade_signed && _signed == true )
	{
		std::cout << executor.getName() << ": ";	
		std::cout << "Drilling noise🔊🔊" << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << _target << " successfully robotized 🤖" << std::endl;
		else
		std::cout << _target << " the action of robotization has failed ❌" << std::endl;
	}
	else
		throw GradeTooLowException();	
}