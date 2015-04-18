// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lombric.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:29 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 07:25:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Lombric.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Lombric::_mobName = "Lombric";
Shape const					Lombric::_mobShape =
	Shape(LOMBRIC_SHAPE, LOMBRIC_COLOR, DEFAULT_COLOR);
bool const					Lombric::_doesMove = true;
bool const					Lombric::_doesShoot = true;
clock_t const				Lombric::_moveCD = CLOCKS_PER_SEC / 20;
int const					Lombric::_moveChancesFactor = 1000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Lombric::Lombric() :
	AObject(), AMovPatternLombric(Lombric::_moveCD, Lombric::_moveChancesFactor)
{
	// std::cout << "[Lombric](main) Ctor called" << std::endl;
	return ;
}

Lombric::Lombric(Lombric const &src) :
	AObject(), AMovPatternLombric(Lombric::_moveCD, Lombric::_moveChancesFactor)
{
	// std::cout << "[Lombric](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Lombric::~Lombric()
{
	// std::cout << "[Lombric]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Lombric::getName() const{return Lombric::_mobName;}
Shape const					&Lombric::getShape() const{return Lombric::_mobShape;}
bool						Lombric::getDoesMove() const{return Lombric::_doesMove;}
bool						Lombric::getDoesShoot() const{return Lombric::_doesShoot;}
int							Lombric::getPosX(void) const{return this->_posX;}
int							Lombric::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Lombric::setPosX(int x){this->_posX = x;}
void						Lombric::setPosY(int y){this->_posY = y;}
void						Lombric::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Lombric::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Lombric::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
