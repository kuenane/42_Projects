// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternMissile.class.cpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:03:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 16:19:04 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "AMovPatternMissile.class.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AMovPatternMissile::AMovPatternMissile(clock_t moveCD, float angle,
									   int srcX, int srcY) :
	_lastMoveTime(std::clock()),
	_moveCD(moveCD),
	_incX(sin(angle)),
	_incY(cos(angle)),
	_coveredX(0.),
	_coveredY(0.),
	_srcX(srcX),
	_srcY(srcY)
{
	// std::cout << "[AMovPatternMissile]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AMovPatternMissile::~AMovPatternMissile()
{
	// std::cout << "[AMovPatternMissile]() Dtor called" << std::endl;
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
void						AMovPatternMissile::move(Game const &g,
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

int							AMovPatternMissile::tryMove(Game const &g)
{
	while (std::clock() >= this->_lastMoveTime + this->_moveCD)
	{
		float	dx = this->_incX * (1. + ((float)(std::rand() % 25)) / 100.);
		float	dy = this->_incY * (1. + ((float)(std::rand() % 25)) / 100.);

		this->_lastMoveTime += this->_moveCD;
		this->_coveredX += dx;
		this->_coveredY += dy;
		move(g, this->getShape(), this->_srcX + (int)round(this->_coveredX),
			 this->_srcY + (int)round(this->_coveredY));
	}
	return (0);
}
