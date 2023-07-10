/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:11 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/19 18:24:44 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H 
# define SHRUBBERYCREATIONFORM_H 

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

private:
	std::string	_target;
	
public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );	
	ShrubberyCreationForm( ShrubberyCreationForm const &copy );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm& operator=( ShrubberyCreationForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<( std::ostream &flux, ShrubberyCreationForm const& ShrubberyCreationForm);

#endif