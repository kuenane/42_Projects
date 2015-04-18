// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scheduler.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 10:41:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 08:56:14 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Scheduler.class.hpp"
#include <cstdlib>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Scheduler::Scheduler(clock_t waitTime, clock_t waveCD) :
	_lastWave(std::clock() + waitTime), _waveCD(waveCD), _waveCount(0)
{
	// std::cout << "[Scheduler]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Scheduler::~Scheduler()
{
	// std::cout << "[Scheduler]() Dtor called" << std::endl;
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
void						Scheduler::tryNewWave(Game &g)
{
	while (std::clock() >= this->_lastWave + this->_waveCD)
	{
		int			pool;
		int			pool2;

		this->_lastWave += this->_waveCD;
		this->_waveCount++;
		pool = (this->_waveCount * 5 / 4) + 1;
		if (this->_waveCount <= 2) // 1 2
			g.popSheep(pool);
		else if (this->_waveCount <= 4) // 3 4
		{
			g.popSheep(pool / 2);
			g.popPig(pool - pool / 2);
		}
		else if (this->_waveCount <= 7) // 5 7 
		{
			g.popSheep(pool / 3);
			g.popLombric(pool / 3);
			g.popPig(pool - (pool / 3) * 2);
		}
		else if (this->_waveCount <= 10) // 8 10
		{
			pool2 = std::rand() % 2 + 1;
			g.popSnake(pool2);
			pool -= 2 * pool2;
			g.popSheep(pool / 3);
			g.popLombric(pool / 3);
			g.popPig(pool - (pool / 3) * 2);
		}
		else if (this->_waveCount <= 12) // 11 12
		{
			pool2 = std::rand() % 3 + 1;
			g.popSnake(pool2);
			pool -= 2 * pool2;
			g.popSheep(pool / 3);
			g.popLombric(pool / 3);
			g.popPig(pool - (pool / 3) * 2);
		}
		else // 13+
		{
			g.popSnake(1);
			pool -= 2;
			pool2 = pool / 3 / 4;
			g.popCentipede(pool2);
			pool -= pool2 * 4;
			g.popSheep(pool / 3);
			g.popLombric(pool / 3);
			g.popPig(pool - (pool / 3) * 2);
			if (std::rand() % 3 == 0)
				g.popFizzy(1);
		}
	}
	return ;
}
