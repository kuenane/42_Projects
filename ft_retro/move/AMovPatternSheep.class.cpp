// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternSheep.class.cpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 07:39:15 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 12:13:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "AMovPatternSheep.class.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AMovPatternSheep::AMovPatternSheep(clock_t moveCD, int strafeChancesFactor) :
	_lastMoveTime(std::clock()),
	_moveCD(moveCD),
	_strafeChancesFactor(strafeChancesFactor)
{
	// std::cout << "[AMovPatternSheep]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AMovPatternSheep::~AMovPatternSheep()
{
	// std::cout << "[AMovPatternSheep]() Dtor called" << std::endl;
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
void						AMovPatternSheep::move(Game const &g,
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

int							AMovPatternSheep::tryMove(Game const &g)
{
	while (std::clock() >= this->_lastMoveTime + this->_moveCD)
	{
		Shape const	&ref = this->getShape();
		int			x = this->getPosX();
		int			y = this->getPosY();
		int			r;

		this->_lastMoveTime += this->_moveCD;
		if ((r = std::rand()) % this->_strafeChancesFactor < 100)
		{
			if (r % 2)
			{
				if (ref.shapeFits(g, x - 1, y + 1))
					this->move(g, ref, x - 1, y + 1);
				else
					this->move(g, ref, x + 1, y + 1);
			}
			else
			{
				if (ref.shapeFits(g, x + 1, y + 1))
					this->move(g, ref, x + 1, y + 1);
				else
					this->move(g, ref, x - 1, y + 1);
			}
		}
		else
			this->move(g, ref, x, y + 1);
	}
	return (0);
}
