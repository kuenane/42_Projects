// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 19:44:12 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 11:10:37 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
Form("Shrubbery-Creation", 145, 137, target)
{
	std::cout << "Shrubbery created." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "Shrubbery destructed." << std::endl;}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream		ofs(this->getTarget() + "_shrubbery");

	(void)executor;
	if (!ofs.fail())
	{
		ofs << "     .#." << std::endl;
		ofs << "    .###." << std::endl;
		ofs << "   .#%##%." << std::endl;
		ofs << "  .%##%###." << std::endl;
		ofs << " .##%###%##." << std::endl;
		ofs << ".#%###%##%##." << std::endl;
		ofs << "      #" << std::endl;
		ofs << "      #" << std::endl;
	}
}
