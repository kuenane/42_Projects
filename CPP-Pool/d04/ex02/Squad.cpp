// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 11:12:52 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 16:25:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Squad.hpp"

Squad::Squad() : _count(0), _units(new ISpaceMarine*){}

Squad::Squad(const Squad &src) : _count(0){*this = src;}

Squad::~Squad(){this->_kill_units();}

Squad				&Squad::operator=(const Squad &rhs)
{
	int		i = -1;

	this->_kill_units();
	this->_count = rhs.getCount();
	_units = new ISpaceMarine*[this->_count];
	while (++i < this->_count)
		this->_units[i] = rhs.getUnit(i)->clone();
	return (*this);
}

int					Squad::getCount() const{return this->_count;}

ISpaceMarine		*Squad::getUnit(int n)
{
	if (n > this->_count || this->_count == 0)
		return NULL;
	return this->_units[n];
}

ISpaceMarine		*Squad::getUnit(int n) const
{
	if (n > this->_count || this->_count == 0)
		return NULL;
	return this->_units[n];
}

int					Squad::push(ISpaceMarine *marine)
{
	int				i = -1;
	ISpaceMarine	**save = this->_units;

	this->_units = new ISpaceMarine*[this->_count + 1];
	while (++i < this->_count)
		this->_units[i] = save[i];
	this->_units[i] = marine->clone();
	delete [] save;
	return (++this->_count);
}

void				Squad::_kill_units(void)
{
	int		i = 0;
	if (this->_count > 0)
	{
		while (i < this->_count)
		{
			delete this->_units[i++];
		}
		delete [] this->_units;
		this->_count = 0;
	}
}
