/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:04 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 16:06:47 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery",145,137), _target("default")
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Shrubbery",145, 137) , _target(target)
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &copy ) : AForm(copy._name, copy._grade_signed, copy._grade_exec)
{
	if (this != &copy)
		_signed = copy._signed;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED "Destructor" CLOSE " called" << std::endl;	
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
		std::cout << executor.getName() << std::endl;	
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