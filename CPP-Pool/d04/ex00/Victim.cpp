// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:22:39 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:55:31 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

Victim::Victim(const std::string name) :
_name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src) :
_name(src.getName())
{
	std::cout << "Some random victim called " << src.getName() << " just cloned !" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim						&Victim::operator=(Victim const &rhs)
{
	this->_name = rhs.getName();
	return (*this);
}

const std::string					&Victim::getName(void) const{return this->_name;}

void	Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream				&operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I'm " << rhs.getName() << " and i like otters !" << std::endl;
	return (o);
}

