// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fizzy.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:42 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 13:50:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Fizzy.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Fizzy::_mobName = "Fizzy";
Shape const					Fizzy::_mobShape =
	Shape(FIZZY_SHAPE, FIZZY_COLOR, DEFAULT_COLOR);
bool const					Fizzy::_doesMove = true;
bool const					Fizzy::_doesShoot = false;
clock_t const				Fizzy::_moveCD = CLOCKS_PER_SEC / 100;
int const					Fizzy::_moveChancesFactor = 10000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Fizzy::Fizzy() :
	AObject(), AMovPatternSheep(Fizzy::_moveCD, Fizzy::_moveChancesFactor)
{
	// std::cout << "[Fizzy](main) Ctor called" << std::endl;
	return ;
}

Fizzy::Fizzy(Fizzy const &src) :
	AObject(), AMovPatternSheep(Fizzy::_moveCD, Fizzy::_moveChancesFactor)
{
	// std::cout << "[Fizzy](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Fizzy::~Fizzy()
{
	// std::cout << "[Fizzy]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Fizzy::getName() const{return Fizzy::_mobName;}
Shape const					&Fizzy::getShape() const{return Fizzy::_mobShape;}
bool						Fizzy::getDoesMove() const{return Fizzy::_doesMove;}
bool						Fizzy::getDoesShoot() const{return Fizzy::_doesShoot;}
int							Fizzy::getPosX(void) const{return this->_posX;}
int							Fizzy::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Fizzy::setPosX(int x){this->_posX = x;}
void						Fizzy::setPosY(int y){this->_posY = y;}
void						Fizzy::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Fizzy::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Fizzy::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
