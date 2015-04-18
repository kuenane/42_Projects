// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 11:39:34 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 15:43:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

public:
	class FormDoesNotExist : public std::exception
	{
	public:
		FormDoesNotExist();
		FormDoesNotExist(const FormDoesNotExist &rhs);
		virtual ~FormDoesNotExist() throw();
		virtual const char *what() const throw();
	private:
		FormDoesNotExist &operator=(FormDoesNotExist const &rhs);
	};

	Intern();
	Form	*makeForm(const std::string &form, const std::string &target) const;
	virtual ~Intern();

protected:

private:
	Intern	&operator=(Intern const &rhs);
	Intern(Intern const &src);

};

#endif
