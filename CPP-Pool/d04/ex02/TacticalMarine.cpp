// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:14:16 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 15:14:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define TM TacticalMarine
#include "TacticalMarine.hpp"

TM::TM()
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TM::TM(const TM &src)
{
	*this = src;
	// std::cout << "Tactical Marine ready for battle" << std::endl;
}

TM::~TM(){std::cout << "Aaargh ..." << std::endl;}

void			TM::battleCry(void) const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void			TM::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void			TM::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

ISpaceMarine	*TM::clone(void) const
{
	return (new TM(*this));
}

TM				&TM::operator=(TM const &rhs)
{
	(void)rhs;
	return (*this);
}
