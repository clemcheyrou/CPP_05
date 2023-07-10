/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:43:54 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/05/22 17:58:40 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern 
{
private:

public:

	Intern( void );
	Intern( Intern const &copy );
	~Intern( void );

	Intern& operator=( Intern const & rhs );

	AForm* formshub(std::string const & target);
	AForm* formpres(std::string const & target);
	AForm* formrob(std::string const & target);
	
	AForm* makeForm( std::string const & nameform, std::string const & target);
};

#endif