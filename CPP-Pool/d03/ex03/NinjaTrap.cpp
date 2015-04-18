// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 22:15:27 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:36:10 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <ctime>
#include <cstdlib>

NinjaTrap::NinjaTrap(const std::string &name) :
ClapTrap(name)
{
	std::cout << "[FR4G-TP] " << name << " built and ready to fight" << std::endl;
	this->_HP = 60;
	this->_MaxHP = 60;
	this->_NRG = 120;
	this->_MaxNRG = 120;
	this->_MlDamage = 60;
	this->_RgDamage = 5;
	this->_ArmDamage = 0;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) :
ClapTrap(src)
{
	std::cout << "[FR4G-TP] " << src.getName() << " cloned and ready to fight" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "[FR4G-TP] " << this->_name << " is died in combat" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
{
	std::cout << "[FR4G-TP] Overload called" << std::endl;
	this->_HP = rhs.getHP();
	this->_MaxHP = rhs.getMaxHP();
	this->_NRG = rhs.getNRG();
	this->_MaxNRG = rhs.getMaxNRG();
	this->_Lvl = rhs.getLvl();
	this->_MlDamage = rhs.getMlDamage();
	this->_RgDamage = rhs.getRgDamage();
	this->_ArmDamage = rhs.getArmDamage();
	return (*this);
}

void NinjaTrap::ninjaShoebox(FragTrap &src) const
{
	std::cout << "[FR4G-TP] " << this->_name << " use kung-fu attack on " << src.getName() << ", causing 10 damages" << std::endl;
	src.takeDamage(10);
}

void NinjaTrap::ninjaShoebox(ScavTrap &src) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attack with its sword (20dmgs) " << src.getName() << std::endl;
	src.takeDamage(20);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &src) const
{
	std::cout << "[FR4G-TP] " << this->_name << " dance with his friend " << src.getName() << std::endl;
}
