// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 11:39:46 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 15:57:50 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Form	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string		formcpy = form;
	int				i = -1;

	while (formcpy[++i] != '\0')
	{
		if(formcpy[i] >= 'A' && formcpy[i] <= 'Z')
			formcpy[i] += 32;
		if(formcpy[i] == ' ' || formcpy[i] == '\t')
			formcpy.erase(i--, 1);
	}
	if (formcpy == "robotomyrequest")
		return (std::cout << "Intern creates RobotomyRequest" << std::endl, new RobotomyRequestForm(target));
	else if (formcpy == "shrubberycreation")
		return (std::cout << "Intern creates ShrubberyCreation" << std::endl, new ShrubberyCreationForm(target));
	else if  (formcpy == "presidentialpardon")
		return (std::cout << "Intern creates PresidentialPardon" << std::endl, new PresidentialPardonForm(target));
	throw Intern::FormDoesNotExist();
	return NULL;
}

Intern::FormDoesNotExist::FormDoesNotExist() : std::exception(){}

Intern::FormDoesNotExist::FormDoesNotExist(const FormDoesNotExist &rhs) :
std::exception(){(void)rhs;}

Intern::FormDoesNotExist::~FormDoesNotExist() throw(){}

const char		*Intern::FormDoesNotExist::what() const throw()
{
	return ("Form Does Not Exist.");
}
