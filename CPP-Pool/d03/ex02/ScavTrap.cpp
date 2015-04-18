// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 17:14:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:25:45 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"
#include <ctime>
#include <cstdlib>

ScavTrap::ScavTrap(const std::string &name) :
ClapTrap(name)
{
	std::cout << "[FR4G-TP] " << name << " leaves ground and is ready to fight" << std::endl;
	this->_HP = 100;
	this->_MaxHP = 100;
	this->_NRG = 50;
	this->_MaxNRG = 50;
	this->_MlDamage = 20;
	this->_RgDamage = 15;
	this->_ArmDamage = 3;
}

ScavTrap::ScavTrap(ScavTrap const &src) :
ClapTrap(src)
{
	std::cout << "[FR4G-TP] " << src.getName() << " reassembly like his friend" << std::endl;
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
