/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:47:07 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 18:02:12 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef AForm* (Intern::*pf)(std::string const & target);

Intern::Intern()
{
};

Intern::Intern( Intern const &copy )
{
	if (this != &copy)
	{};
	return;
};

Intern::~Intern()
{
};

Intern& Intern::operator=( Intern const & rhs )
{
	if (this != &rhs)
	{};
	return (*this);
};

AForm* Intern::formshub(std::string const & target)
{
	return (new ShrubberyCreationForm(target));	
} 

AForm* Intern::formpres(std::string const & target)
{
	return (new PresidentialPardonForm(target));	
} 

AForm* Intern::formrob(std::string const & target)
{
	return (new RobotomyRequestForm(target));	
} 

AForm* Intern::makeForm( std::string const & nameform, std::string const & target)
{
	std::string name[] = {"shrubbery", "presidential", "robotomy"};	
	pf funcs[] = { &Intern::formshub, &Intern::formpres, &Intern::formrob };

	for (int i = 0; i < 3; i++)
	{
		if (nameform == name[i])
		{
			std::cout << "Intern creates " << nameform << std::endl;
			return((this->*funcs[i])(target));
		}
	}
	std::cout << "Form doesn't exist! Choose between : shrubbery, presidential, robotomy" << std::endl;
	return (NULL);
}