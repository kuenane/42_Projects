// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/14 09:33:54 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:17:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type){}

Weapon::~Weapon(void){}

void	Weapon::setType(const std::string &type){this->_type = type;}

const std::string &Weapon::getType(void) const{return (this->_type);}
