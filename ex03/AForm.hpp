/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:24:02 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/12 16:29:31 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H 
# define AFORM_H 

# include "Bureaucrat.hpp"
# include <iostream>
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	const int		_grade_signed;
	const int 		_grade_exec;
	bool			_signed;

public:

	AForm( void );
	AForm(std::string name, const int grade_signed, const int grade_exec);
	AForm( const AForm &copy );
	virtual ~AForm( void );

	AForm& operator=( AForm const & rhs );

	std::string 	getName() const;
	int				getGradeSigned() const;
	int 			getGradeExec() const;
	bool 			getSigned() const;

	void			beSigned(Bureaucrat const &bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator<<( std::ostream &flux, AForm const& form);

#endif