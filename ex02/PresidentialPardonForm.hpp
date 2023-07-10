/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:56:41 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/07/10 17:32:42 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H 
# define PRESIDENTIALPARDONFORM_H 

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{

private:
	std::string	_target;
	
public:

	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );	
	PresidentialPardonForm( PresidentialPardonForm const &copy );
	~PresidentialPardonForm( void );

	PresidentialPardonForm& operator=( PresidentialPardonForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<( std::ostream &flux, PresidentialPardonForm const& PresidentialPardonForm);

#endif