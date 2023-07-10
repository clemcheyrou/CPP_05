/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:24:02 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/18 22:39:50 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H 
# define FORM_H 

# include "Bureaucrat.hpp"
# include <iostream>
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Bureaucrat;

class Form
{
private:
	std::string	_name;
	int const	_grade_signed;
	int const	_grade_exec;
	bool		_signed;

public:

	Form( void );
	Form(std::string name, int grade_signed, int grade_exec);
	Form( Form const &copy );
	~Form( void );

	Form& operator=( Form const & rhs );

	std::string 	getName() const;
	int				getGradeSigned() const;
	int 			getGradeExec() const;
	bool 			getSigned() const;

	void			beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<( std::ostream &flux, Form const& form);

#endif