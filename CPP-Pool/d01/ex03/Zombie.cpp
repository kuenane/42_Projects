// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:08:34 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:57:46 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

Zombie::Zombie(void)
{
	int		random;

	std::srand(std::time(NULL));
	random = std::rand();
	if (random % 4 == 0)
		this->_name = "Toto";
	else if (random % 4 == 1)
		this->_name = "Titi";
	else if (random % 4 == 2)
		this->_name = "Tata";
	else
		this->_name = "Tutu";
	if (random % 3 == 0)
		this->_type = "Chief";
	else if (random % 3 == 1)
		this->_type = "Soldier";
	else
		this->_type = "Slave";
	std::cout << "Zombie constructed" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie destructed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}
