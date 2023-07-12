/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:40:31 by ccheyrou         ###   ########.fr       */
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
	std::cout << std::endl;
	std::cout << "---------TEST 1----------" << std::endl;
	std::cout << std::endl;	

	try
	{
		Bureaucrat Tim("Tim", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "---------TEST 2----------" << std::endl;
	std::cout << std::endl;	

	try	
	{
		ShrubberyCreationForm form("Tim");
		Bureaucrat Tim("Tim", 1);
		Tim.signForm(form);
		Tim.executeForm(form);
		std::ifstream ifs("Tim_shrubbery");
		if (!ifs.is_open())
			return(std::cout << "KO" << std::endl, 0);
		std::string str;
		while (getline(ifs, str))
			std::cout << str << std::endl;
		ifs.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	
	std::cout << std::endl;
	std::cout << "---------TEST 3----------" << std::endl;
	std::cout << std::endl;	

	try
	{
		PresidentialPardonForm form("Tom");
		Bureaucrat Tom("Tom", 10);
		Tom.signForm(form);
		Tom.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}

	std::cout << std::endl;
	std::cout << "---------TEST 4----------" << std::endl;
	std::cout << std::endl;	

	try
	{
		RobotomyRequestForm form("Titi");
		Bureaucrat Titi("Titi", 150);
		Titi.signForm(form);
		Titi.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}

	std::cout << std::endl;
	std::cout << "---------TEST 5----------" << std::endl;
	std::cout << std::endl;	

	try
	{
		RobotomyRequestForm form("Toto");
		Bureaucrat Toto("Toto", 25);
		Toto.signForm(form);
		Toto.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
}
