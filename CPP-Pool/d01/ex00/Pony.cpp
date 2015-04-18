// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 14:03:44 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 12:59:10 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

Pony::Pony(const std::string &name, int lvl) :
_name(name), _lvl(lvl)
{
	std::cout << "Pony constructed" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "Pony destructed" << std::endl;
}

void Pony::sayHello(void) const
{
	std::cout << "Hello, I'm " << this->_name << ", a pony level " << this->_lvl << std::endl;
}
