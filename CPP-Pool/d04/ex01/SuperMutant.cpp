// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 16:43:34 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 08:51:52 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) :
	Enemy(src.getHp(), src.getType())
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant					&SuperMutant::operator=(SuperMutant const &rhs)
{
	this->_type = rhs.getType();
	this->_hp = rhs.getHp();
	return (*this);
}

void						SuperMutant::takeDamage(int dmg)
{
	Enemy::takeDamage(dmg - 3);
}
