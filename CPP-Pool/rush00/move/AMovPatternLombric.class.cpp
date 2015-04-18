// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternLombric.class.cpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 15:13:08 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 07:01:23 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "AMovPatternLombric.class.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AMovPatternLombric::AMovPatternLombric(clock_t moveCD, int strafeChancesFactor) :
	_lastMoveTime(std::clock()),
	_moveCD(moveCD),
	_strafeChancesFactor(strafeChancesFactor)
{
	// std::cout << "[AMovPatternLombric]() Ctor called" << std::endl;
	this->_direction = std::rand() % 2 ? 'r' : 'l';
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AMovPatternLombric::~AMovPatternLombric()
{
	// std::cout << "[AMovPatternLombric]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						AMovPatternLombric::move(Game const &g,
												   Shape const &s, int x, int y)
{
	this->setPosX(x);
	this->setPosY(y);
	if (y - s.getTopSize() >= g.getMaxY())
		this->setDeleteObject(true);
	else
		s.putShape(g, x, y);
	return ;
}

int							AMovPatternLombric::tryMove(Game const &g)
{
	while (std::clock() >= this->_lastMoveTime + this->_moveCD)
	{
		Shape const	&ref = this->getShape();
		int			x = this->getPosX();
		int			y = this->getPosY();
		int			margin = (g.getMaxX() / 7);

		this->_lastMoveTime += this->_moveCD;
		if (x >= g.getMaxX() - 2)
			_direction = 'l';
		else if (x <= 2)
			_direction = 'r';
		if (_direction == 'r')
		{
			if (x <= margin || x >= (g.getMaxX() - margin))
				this->move(g, ref, x + 1, y + 1);
			else
				this->move(g, ref, x + 1, y);
		}
		else
		{
			if (x <= margin || x >= (g.getMaxX() - margin))
				this->move(g, ref, x - 1, y + 1);
			else
				this->move(g, ref, x - 1, y);
		}
	}
	return (0);
}
