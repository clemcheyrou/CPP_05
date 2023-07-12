/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:31:09 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:42:40 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		Bureaucrat Tim("Tim", 150);
		Tim.incrementGrade();
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
		Bureaucrat Tim("Tim", 150);
		Tim.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "---------TEST 4----------" << std::endl;
	std::cout << std::endl;

	Bureaucrat Jose("Jose", 49);
	std::cout << Jose << std::endl;
	
}