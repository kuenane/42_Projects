// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:44:07 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 14:55:21 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
AWeapon("Plasma Rifle", 5, 21)
{
	//
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
	AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle					&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	this->_name = rhs.getName();
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this);
}

void						PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
