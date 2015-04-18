// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 15:07:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:21:21 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

FragTrap::FragTrap(const std::string &name) :
ClapTrap(name)
{
	std::cout << "[FR4G-TP] " << name << " built and ready to fight" << std::endl;
	this->_HP = 100;
	this->_MaxHP = 100;
	this->_NRG = 100;
	this->_MaxNRG = 100;
	this->_MlDamage = 30;
	this->_RgDamage = 20;
	this->_ArmDamage = 5;
}

FragTrap::FragTrap(FragTrap const &src) :
ClapTrap(src)
{
	std::cout << "[FR4G-TP] " << src.getName() << " cloned and ready to fight" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FR4G-TP] " << this->_name << " is died in combat" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int		random;
	
	if (this->_NRG >= 25)
	{
		std::srand(std::time(0));
		random = std::rand();
		if (random % 5 == 0)
			plugAttack(target);	
		else if (random % 5 == 1)
			thorAttack(target);
		else if (random % 5 == 2)
			zazAttack(target);
		else if (random % 5 == 3)
			NSAttack(target);
		else
			stCardAttack(target);
		this->_NRG -= 25;
	}
	else
		std::cout << "Too few energy points to launch vaulthunter attack." << std::endl;
}

void FragTrap::plugAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " with a plug, causing " << this->_MlDamage * 2 << "points of damage !" <<std::endl;
}

void FragTrap::thorAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " with the Thor hammer, causing " << this->_RgDamage * 2 << "points of damage !" <<std::endl;
}

void FragTrap::zazAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " with the Zaz axe, causing " << this->_RgDamage << "points of damage !" <<std::endl;
}

void FragTrap::NSAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " spank (like NS) " << target << ", causing " << this->_MlDamage << "points of damage !" <<std::endl;
}

void FragTrap::stCardAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " with his student card, causing " << this->_RgDamage << "points of damage !" <<std::endl;
}
