/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 14:15:37 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Bureaucrat Tim("Tim", 5);
		Form	firstForm("First", 6, 3);
		firstForm.beSigned(Tim);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Tim("Tim", 5);
		Form	firstForm("First", 1, 3);
		firstForm.beSigned(Tim);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat Tim("Tim", 5);
		Form	firstForm("First", 6, 3);
		firstForm.beSigned(Tim);
		Tim.signForm(firstForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Form	firstForm("First", 6, 3);
	std::cout << firstForm << std::endl;	
}