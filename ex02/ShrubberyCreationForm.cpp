/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:08 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/10 17:37:17 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery",145,137), _target("default")
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery",145, 137) , _target(target)
{
	std::cout << GREEN "Constructor" CLOSE " called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &copy ) : AForm(copy._name, copy._grade_signed, copy._grade_exec)
{
	if (this != &copy)
		_signed = copy._signed;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED "Destructor" CLOSE " called" << std::endl;	
	return;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
		_signed = rhs._signed;
	return(*this);	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < _grade_signed && _signed == true)
	{	
		std::string  name = _target + "_shrubery"; 
		std::ofstream ofs(name.c_str());

		ofs << 
		"               ,@@@@@@@,\n\
		,,,.   ,@@@@@@/@@,  .oo8888o.\n\
		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
	`&%\\ ` /%&'    |.|        \\ '|8'\n\
		|o|        | |         | |\n\
		|.|        | |         | |\n\
		\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
		" << std::endl;

		ofs.close();
	}
	else
		throw GradeTooLowException();	
}