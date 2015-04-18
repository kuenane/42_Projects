// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternDefault.class.cpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 10:43:59 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 07:42:53 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "AMovPatternDefault.class.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AMovPatternDefault::AMovPatternDefault(clock_t moveCD, int moveChancesFactor) :
	_lastMoveTime(std::clock()),
	_moveCD(moveCD),
	_moveChancesFactor(moveChancesFactor)
{
	// std::cout << "[AMovPatternDefault]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AMovPatternDefault::~AMovPatternDefault()
{
	// std::cout << "[AMovPatternDefault]() Dtor called" << std::endl;
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
void					AMovPatternDefault::move(Game const &g, Shape const &s,
												 int x, int y)
{
	this->setPosX(x);
	this->setPosY(y);
	s.putShape(g, x, y);
	return ;
}

int						AMovPatternDefault::tryMove(Game const &g)
{
	int		r;
	
	if (std::clock() >= this->_lastMoveTime + this->_moveCD &&
		(r = std::rand()) % this->_moveChancesFactor < 100)
	{
		Shape const	&ref = this->getShape();
		int			x = this->getPosX();
		int			y = this->getPosY();

		if (r % 2)
		{
			if (ref.shapeFits(g, x - 1, y))
				this->move(g, ref, x - 1, y);
			else if (ref.shapeFits(g, x + 1, y))
				this->move(g, ref, x + 1, y);
		}
		else
		{
			if (ref.shapeFits(g, x + 1, y))
				this->move(g, ref, x + 1, y);
			else if (ref.shapeFits(g, x - 1, y))
				this->move(g, ref, x - 1, y);
		}
		this->_lastMoveTime = std::clock();
	}
	return (1);
}
