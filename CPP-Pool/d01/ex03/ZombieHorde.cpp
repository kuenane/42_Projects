// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 14:49:41 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:55:43 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	this->_nbzomb = n;
	this->_zombtab = new Zombie[n];
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_zombtab;
}

void ZombieHorde::announce(void) const
{
	int		i;

	i = -1;
	while (++i < this->_nbzomb)
		this->_zombtab[i].announce();
}
