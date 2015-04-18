// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:56:48 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 10:54:50 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(const std::string &name) :
_name(name), _AP(40), _Weapon(NULL)
{
}

Character::Character(Character const &src) :
_name(src.getName()), _AP(src.getAP()), _Weapon(src.getWeapon())
{
}

Character::~Character()
{
}

Character					&Character::operator=(Character const &rhs)
{
	this->_name = rhs.getName();
	this->_AP = rhs.getAP();
	this->_Weapon = rhs.getWeapon();
	return (*this);
}

const std::string			&Character::getName(void) const{return this->_name;}
int							Character::getAP(void) const{return this->_AP;}
AWeapon						*Character::getWeapon(void) const{return this->_Weapon;}

void						Character::recoverAP()
{
	std::cout << "Recovered 10 AP." << std::endl;
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
}

void						Character::equip(AWeapon *weapon)
{
	this->_Weapon = weapon;
}

void						Character::attack(Enemy *target)
{
	if (target == NULL)
		std::cout << "Target is invalid." << std::endl;
	else if (this->_Weapon == NULL)
		std::cout << "Choose a weapon before." << std::endl;
	else if (this->_AP < this->_Weapon->getAPCost())
		std::cout << "Not enough AP to attack." << std::endl;
	else
	{
		std::cout << this->_name << " attacks " << target->getType() << " with a " << this->_Weapon->getName() << std::endl;
		this->_AP -= this->_Weapon->getAPCost();
		if (this->_AP < 0)
			this->_AP = 0;
		this->_Weapon->attack();
		target->takeDamage(this->_Weapon->getDamage());
		if (target->getHp() <= 0)
			delete target;
	}
}

std::ostream	&operator<<(std::ostream &o, const Character &rhs)
{
	if (rhs.getWeapon() == NULL)
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	return (o);
}
