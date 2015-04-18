// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:08:48 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:51:47 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(void)
{
	this->_Zombie_Type = "NoType";
}

ZombieEvent::~ZombieEvent(void){}

void ZombieEvent::setZombieType(const std::string &type)
{
	std::cout << "Zombie type set" << std::endl;
	this->_Zombie_Type = type;
}

Zombie *ZombieEvent::newZombie(const std::string &name)
{
	return (new Zombie(name, this->_Zombie_Type));
}

void ZombieEvent::randomChump(void)
{
    int				random;
	std::string		nm;
	
	std::srand(std::time(NULL));
	random = std::rand();
	if (random % 4 == 0)
		nm = "Toto";
	else if (random % 4 == 1)
		nm = "Tata";
	else if (random % 4 == 2)
		nm = "Titi";
	else
		nm = "Tutu";
	Zombie	tmp(nm, this->_Zombie_Type);
	tmp.announce();
}
