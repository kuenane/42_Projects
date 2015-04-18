// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 11:08:53 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat				bc("target", 1);
	Bureaucrat				bc2("target", 150);
	ShrubberyCreationForm 	sc("target");
	RobotomyRequestForm	 	rb("target");
	PresidentialPardonForm 	pp("target");

	srand(time(NULL));
	std::cout << std::endl;
	bc.executeForm(sc);
	bc.executeForm(rb);
	bc.executeForm(pp);
	std::cout << std::endl;
	bc.signForm(sc);
	bc.signForm(rb);
	bc.signForm(pp);
	std::cout << std::endl;
	bc2.executeForm(sc);
	bc2.executeForm(rb);
	bc2.executeForm(pp);
	std::cout << std::endl;
	bc.executeForm(sc);
	bc.executeForm(rb);
	bc.executeForm(pp);
	std::cout << std::endl;
	return (0);

}
