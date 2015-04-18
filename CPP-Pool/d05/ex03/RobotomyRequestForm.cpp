// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 09:24:14 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:37:05 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
Form("Robotomy-Request", 145, 137, target)
{
	std::cout << "Robotomy created." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "Robotomy destructed." << std::endl;}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "Brrr brrrr brrrrrrr brr... ";
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Nothing happened.." << std::endl;
}
