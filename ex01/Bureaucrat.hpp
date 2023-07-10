/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:43:15 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 14:07:49 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include "Form.hpp"
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Form;

class Bureaucrat {

private:
	std::string _name;
	int			_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat( Bureaucrat const & copy );
	~Bureaucrat();

	Bureaucrat& operator=( Bureaucrat const & rhs );

	std::string getName() const;
	int getGrade() const;

	int incrementGrade();
	int decrementGrade();
	
	void signForm(Form const &form) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return (ORANGE "ERROR: Grade too High" CLOSE);
		}
	};
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return (ORANGE "ERROR: Grade too Low" CLOSE);
		}
	};
};

std::ostream &operator<<( std::ostream &flux, Bureaucrat const& bureaucrat);


#endif