/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:58:06 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/19 18:25:35 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H 
# define ROBOTOMYREQUESTFORM_H 

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>
# define ORANGE "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define CLOSE "\033[0m"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{

private:
	std::string	_target;
	
public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );	
	RobotomyRequestForm( RobotomyRequestForm const &copy );
	~RobotomyRequestForm( void );

	RobotomyRequestForm& operator=( RobotomyRequestForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<( std::ostream &flux, RobotomyRequestForm const& RobotomyRequestForm);

#endif