// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:56:17 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 14:55:33 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PowerFist.hpp"

PowerFist::PowerFist() :
	AWeapon("Power Fist", 8, 50)
{
	//
}

PowerFist::PowerFist(PowerFist const &src) :
	AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
}

PowerFist::~PowerFist()
{
}

PowerFist					&PowerFist::operator=(PowerFist const &rhs)
{
	this->_name = rhs.getName();
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this);
}

void						PowerFist::	attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
