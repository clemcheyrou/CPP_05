/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:23:05 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <fstream>
#include <math.h>

void test_form(AForm &form, Bureaucrat &correct, Bureaucrat &wrong)
{
	std::cout << std::endl;
	std::cout << "## WRONG ##" << std::endl;
	wrong.signForm(form);
	wrong.executeForm(form);
	std::cout << std::endl;
	std::cout << "## CORRECT ##" << std::endl;
	correct.signForm(form);
	correct.executeForm(form);
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));

	Bureaucrat    Simba("Simba", 1);
	Bureaucrat    Scar("Scar", 150);
	Intern        intern;
	AForm        *form;

	std::cout << std::endl;
	std::cout << "---------TEST 1----------" << std::endl;
	std::cout << std::endl;

	try
	{
		form = intern.makeForm("shrubbery", "target");
		test_form(*form, Simba, Scar);
		delete form;
	}
	catch (const std::exception &e)
    {
		std::cout << e.what() << std::endl;
    }
	
	std::cout << std::endl;
	std::cout << "---------TEST 2----------" << std::endl;
	std::cout << std::endl;

	try
	{
		form = intern.makeForm("presidential", "target");
		test_form(*form, Simba, Scar);
		delete form;
	}
	catch (const std::exception &e)
    {
		std::cout << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "---------TEST 3----------" << std::endl;
	std::cout << std::endl;

	try
	{
		form = intern.makeForm("robotomy", "target");
		test_form(*form, Simba, Scar);
		delete form;
	}
	catch (const std::exception &e)
    {
		std::cout << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "---------TEST 4----------" << std::endl;
	std::cout << std::endl;

	try
	{
		form = intern.makeForm("WrongName", "target");
		test_form(*form, Simba, Scar);
		delete form;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
