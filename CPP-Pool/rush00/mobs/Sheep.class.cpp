// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sheep.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 09:12:38 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 09:42:52 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Sheep.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Sheep::_mobName = "Sheep";
Shape const					Sheep::_mobShape =
	Shape(SHEEP_SHAPE, SHEEP_COLOR, DEFAULT_COLOR);
bool const					Sheep::_doesMove = true;
bool const					Sheep::_doesShoot = false;
clock_t const				Sheep::_moveCD = CLOCKS_PER_SEC / 10;
int const					Sheep::_moveChancesFactor = 1000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Sheep::Sheep() :
	AObject(), AMovPatternSheep(Sheep::_moveCD, Sheep::_moveChancesFactor)
{
	// std::cout << "[Sheep](main) Ctor called" << std::endl;
	return ;
}

Sheep::Sheep(Sheep const &src) :
	AObject(), AMovPatternSheep(Sheep::_moveCD, Sheep::_moveChancesFactor)
{
	// std::cout << "[Sheep](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Sheep::~Sheep()
{
	// std::cout << "[Sheep]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Sheep::getName() const{return Sheep::_mobName;}
Shape const					&Sheep::getShape() const{return Sheep::_mobShape;}
bool						Sheep::getDoesMove() const{return Sheep::_doesMove;}
bool						Sheep::getDoesShoot() const{return Sheep::_doesShoot;}
int							Sheep::getPosX(void) const{return this->_posX;}
int							Sheep::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Sheep::setPosX(int x){this->_posX = x;}
void						Sheep::setPosY(int y){this->_posY = y;}
void						Sheep::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Sheep::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Sheep::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
