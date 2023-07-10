/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/10 17:34:42 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>

int main()
{
	try
	{
		Bureaucrat Tim("Tim", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Tim("Tim", 150);
		Tim.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Tim("Tim", 149);
		Tim.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try	
	{
		ShrubberyCreationForm form("Tim");
		Bureaucrat Tim("Tim", 1);
		form.beSigned(Tim);
		Tim.executeForm(form);
		std::ifstream ifs("Tim_shrubery");
		if (!ifs.is_open())
			return(std::cout << "KO" << std::endl, 0);
		std::string str;
		while (getline(ifs, str))
			std::cout << str << std::endl;
		ifs.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	
	try
	{
		PresidentialPardonForm form("Tom");
		Bureaucrat Tom("Tom", 10);
		form.beSigned(Tom);
		Tom.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	
	try
	{
		RobotomyRequestForm form("Titi");
		Bureaucrat Titi("Titi", 150);
		form.beSigned(Titi);
		Titi.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	
	try
	{
		RobotomyRequestForm form("Toto");
		Bureaucrat Toto("Toto", 25);
		form.beSigned(Toto);
		Toto.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
}
