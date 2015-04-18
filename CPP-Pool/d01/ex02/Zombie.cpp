// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:08:34 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:01:44 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name, const std::string &type) :
_name(name), _type(type)
{
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
