// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:13:49 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 09:33:48 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
_name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::AWeapon(AWeapon const &src) :
_name(src.getName()), _apcost(src.getAPCost()), _damage(src.getDamage())
{
}

AWeapon::~AWeapon(){}

AWeapon						&AWeapon::operator=(AWeapon const &rhs)
{
	this->_name = rhs.getName();
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this);
}

const std::string	&AWeapon::getName(void) const{return this->_name;}
int					AWeapon::getAPCost(void) const{return this->_apcost;}
int					AWeapon::getDamage(void) const{return this->_damage;}
