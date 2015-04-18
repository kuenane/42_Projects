// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:14:16 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 15:14:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define AT AssaultTerminator
#include "AssaultTerminator.hpp"

AT::AT()
{
	std::cout << "* teleports from space *" << std::endl;
}

AT::AT(const AT &src)
{
	*this = src;
	// std::cout << "* teleports from space *" << std::endl;
}

AT::~AT(){std::cout << "I'll be back ..." << std::endl;}

void			AT::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void			AT::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void			AT::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

ISpaceMarine	*AT::clone(void) const
{
	return (new AT(*this));
}

AT				&AT::operator=(AT const &rhs)
{
	(void)rhs;
	return (*this);
}
