// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 17:14:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:17:37 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"
#include <ctime>
#include <cstdlib>

ScavTrap::ScavTrap(const std::string &name):
_name(name), _HP(100), _MaxHP(100), _NRG(50), _MaxNRG(50), _Lvl(1), _MlDamage(20), _RgDamage(15), _ArmDamage(3)
{
	std::cout << "[FR4G-TP] " << name << " leaves ground and is ready to fight" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src):
_name(src.getName())
{
	std::cout << "[FR4G-TP] " << this->_name << " reassembly like his friend" << std::endl;
	this->_HP = src.getHP();
	this->_MaxHP = src.getMaxHP();
	this->_NRG = src.getNRG();
	this->_MaxNRG = src.getMaxNRG();
	this->_Lvl = src.getLvl();
	this->_MlDamage = src.getMlDamage();
	this->_RgDamage = src.getRgDamage();
	this->_ArmDamage = src.getArmDamage();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[FR4G-TP] " << this->_name << " explode in thousand pieces" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "[FR4G-TP] Overload called (but its a chineese copy)" << std::endl;
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

const std::string &ScavTrap::getName(void) const{return this->_name;}
int ScavTrap::getHP(void) const{return this->_HP;}
int ScavTrap::getMaxHP(void) const{return this->_MaxHP;}
int ScavTrap::getNRG(void) const{return this->_NRG;}
int ScavTrap::getMaxNRG(void) const{return this->_MaxNRG;}
int ScavTrap::getLvl(void) const{return this->_Lvl;}
int ScavTrap::getMlDamage(void) const{return this->_MlDamage;}
int ScavTrap::getRgDamage(void) const{return this->_RgDamage;}
int ScavTrap::getArmDamage(void) const{return this->_ArmDamage;}

void ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " launch a rocket to " << target << ", causing " << this->_RgDamage << "points of damage !" <<std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "[FR4G-TP] " << this->_name << " attacks " << target << " with its grips, causing " << this->_MlDamage << "points of damage !" <<std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "[FR4G-TP] " << this->_name << " is repaired of " << amount << " HP." <<std::endl;
	this->_HP += amount;
	if (this->_HP > this->_MaxHP)
		this->_HP = this->_MaxHP;
}

void ScavTrap::challengeNewcomer()
{
	int		random;
	
	if (this->_NRG >= 25)
	{
		std::srand(std::time(0));
		random = std::rand();
		if (random % 5 == 0)
			plugChallenge();	
		else if (random % 5 == 1)
			thorChallenge();
		else if (random % 5 == 2)
			zazChallenge();
		else if (random % 5 == 3)
			NSChallenge();
		else
			stCardChallenge();
		this->_NRG -= 25;
	}
	else
		std::cout << "Too few energy points to launch vaulthunter attack." << std::endl;
}

void ScavTrap::plugChallenge(void) const
{
	std::cout << "[FR4G-TP] Can you use this plug with Sylvain?" <<std::endl;
}

void ScavTrap::thorChallenge(void) const
{
	std::cout << "[FR4G-TP] Can you hit Thor with its hammer?" <<std::endl;
}

void ScavTrap::zazChallenge(void) const
{
	std::cout << "[FR4G-TP] Can you slice Zaz with its axe?" <<std::endl;
}

void ScavTrap::NSChallenge(void) const
{
	std::cout << "[FR4G-TP] Can you spank NS in the holodeck?" <<std::endl;
}

void ScavTrap::stCardChallenge(void) const
{
	std::cout << "[FR4G-TP] Can you send your student card in someone in this cluster?" <<std::endl;
}
