// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AShootPatternDefault.class.cpp                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 11:14:10 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/24 06:40:25 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "AShootPatternDefault.class.hpp"
#include <AObject.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AShootPatternDefault::AShootPatternDefault(int num, clock_t shootCD,
										   int shootChancesFactor,
										   clock_t missileMovCD) :
	_num(num > 0 ? num : 1), _shootCD(shootCD),
	_shootChancesFactor(shootChancesFactor), _lastShootTime(std::clock()),
	_missileMovCD(missileMovCD)
{
//	std::cout << "[AShootPatternDefault]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AShootPatternDefault::~AShootPatternDefault()
{
//	std::cout << "[AShootPatternDefault]() Dtor called" << std::endl;
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
int							AShootPatternDefault::tryShoot(Game &g)
{
	if (std::clock() >= this->_lastShootTime + this->_shootCD &&
		std::rand() % this->_shootChancesFactor < 100)
	{
		float			angle = (-3.14159 / 10.) * (float)(this->_num - 1) / 2.;

		this->_lastShootTime += this->_shootCD;
		for (int i = 0; i < this->_num; i++)
		{
			try
			{
				g.popMissile(dynamic_cast<AObject*>(this), angle,
							 (clock_t)(CLOCKS_PER_SEC / 45));
			}
			catch (const std::bad_cast& e)
			{
				g.leave_game(e.what());
			}
			angle += (3.14159 / 10.);
		}
	}
	return (0);
}
