// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 20:51:04 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:29:10 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) :
_name(name), _Lvl(1)
{
	std::cout << "[FR4G-TP] Mother ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) :
_name(src.getName())
{
	std::cout << "[FR4G-TP] Mother ClapTrap copied" << std::endl;
    this->_HP = src.getHP();
	this->_MaxHP = src.getMaxHP();
	this->_NRG = src.getNRG();
	this->_MaxNRG = src.getMaxNRG();
	this->_Lvl = src.getLvl();
	this->_MlDamage = src.getMlDamage();
	this->_RgDamage = src.getRgDamage();
	this->_ArmDamage = src.getArmDamage();
}

ClapTrap::~ClapTrap()
{
	std::cout << "[FR4G-TP] Mother ClapTrap destructed" << std::endl;
}

ClapTrap					&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "[FR4G-TP] Mother ClapTrap overload called" << std::endl;
	(void)rhs;
	return (*this);
}

const std::string &ClapTrap::getName(void) const{return this->_name;}
int ClapTrap::getHP(void) const{return this->_HP;}
int ClapTrap::getMaxHP(void) const{return this->_MaxHP;}
int ClapTrap::getNRG(void) const{return this->_NRG;}
int ClapTrap::getMaxNRG(void) const{return this->_MaxNRG;}
int ClapTrap::getLvl(void) const{return this->_Lvl;}
int ClapTrap::getMlDamage(void) const{return this->_MlDamage;}
int ClapTrap::getRgDamage(void) const{return this->_RgDamage;}
int ClapTrap::getArmDamage(void) const{return this->_ArmDamage;}

void ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " at range, causing " << this->_RgDamage << "points of damage !" <<std::endl;
}

void ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " at melee, causing " << this->_MlDamage << "points of damage !" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	amount -= this->_ArmDamage;
	if (amount <= 0)
	{
		amount = 0;
		std::cout << "[FR4G-TP] " << this->_name << " don't take damages (due to his resistance armour)" << std::endl;
	}
	else
	{
		std::cout << "[FR4G-TP] " << this->_name << " take " << amount << " damages." <<std::endl;
		this->_HP -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[FR4G-TP] " << this->_name << " is repaired of " << amount << " HP." <<std::endl;
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;
}
