// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 19:44:12 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:38:31 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
Form("Presidential-Pardon", 25, 5, target)
{
	std::cout << "Presidential created." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructed." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
