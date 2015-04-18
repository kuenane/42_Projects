// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 15:07:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:13:17 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <ctime>
#include <cstdlib>

FragTrap::FragTrap(const std::string &name):
_name(name), _HP(100), _MaxHP(100), _NRG(100), _MaxNRG(100), _Lvl(1), _MlDamage(30), _RgDamage(20), _ArmDamage(5)
{
	std::cout << "[FR4G-TP] " << name << " built and ready to fight" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src):
_name(src.getName())
{
	std::cout << "[FR4G-TP] " << this->_name << " cloned and ready to fight" << std::endl;
	this->_HP = src.getHP();
	this->_MaxHP = src.getMaxHP();
	this->_NRG = src.getNRG();
	this->_MaxNRG = src.getMaxNRG();
	this->_Lvl = src.getLvl();
	this->_MlDamage = src.getMlDamage();
	this->_RgDamage = src.getRgDamage();
	this->_ArmDamage = src.getArmDamage();
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

const std::string &FragTrap::getName(void) const{return this->_name;}
int FragTrap::getHP(void) const{return this->_HP;}
int FragTrap::getMaxHP(void) const{return this->_MaxHP;}
int FragTrap::getNRG(void) const{return this->_NRG;}
int FragTrap::getMaxNRG(void) const{return this->_MaxNRG;}
int FragTrap::getLvl(void) const{return this->_Lvl;}
int FragTrap::getMlDamage(void) const{return this->_MlDamage;}
int FragTrap::getRgDamage(void) const{return this->_RgDamage;}
int FragTrap::getArmDamage(void) const{return this->_ArmDamage;}

void FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " at range, causing " << this->_RgDamage << "points of damage !" <<std::endl;
}

void FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " at melee, causing " << this->_MlDamage << "points of damage !" <<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "[FR4G-TP] " << this->_name << " is repaired of " << amount << " HP." <<std::endl;
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;
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
