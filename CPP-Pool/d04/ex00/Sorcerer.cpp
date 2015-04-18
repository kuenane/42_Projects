// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 08:58:07 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:47:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string name, const std::string title) :
_name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) :
	_name(src.getName()), _title(src.getTitle())
{
	std::cout << src.getName() << ", " << src.getTitle() << ", is cloned !" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs)
{
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return (*this);
}

const std::string		&Sorcerer::getName(void) const{return this->_name;}
const std::string		&Sorcerer::getTitle(void) const{return this->_title;}

void	Sorcerer::polymorph(const Victim &vict) const{vict.getPolymorphed();}

std::ostream				&operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}

