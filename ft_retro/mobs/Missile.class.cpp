// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:42 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 12:11:17 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Missile.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Missile::_mobName = "Missile";
Shape const					Missile::_mobShape =
	Shape(MISSILE_SHAPE, MISSILE_COLOR, DEFAULT_COLOR);
Shape const					Missile::_mobShapePlayer =
	Shape(MISSILE_SHAPE, MISSILE_COLOR_PLAYER, DEFAULT_COLOR);
bool const					Missile::_doesMove = true;
bool const					Missile::_doesShoot = false;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Missile::Missile(float angle, int srcX, int srcY, int movCD) :
	AObject(), AMovPatternMissile(movCD, angle, srcX, srcY),
	_angle(angle), _srcX(srcX), _srcY(srcY), _movCD(movCD)
{
	// std::cout << "[Missile](main) Ctor called" << std::endl;
	return ;
}

Missile::Missile(Missile const &src) :
	AObject(), AMovPatternMissile(src.getMovCD(),
								src.getAngle(), src.getSrcX(), src.getSrcY()),
	_angle(src.getAngle()), _srcX(src.getSrcX()), _srcY(src.getSrcY()),
	_movCD(src.getMovCD())
{
	// std::cout << "[Missile](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Missile::~Missile()
{
	// std::cout << "[Missile]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Missile::getName() const{return Missile::_mobName;}
Shape const					&Missile::getShape() const
{
	if (this->_angle > 3.14159 / 2 || this->_angle < -3.14159 / 2)
		return Missile::_mobShapePlayer;
	return Missile::_mobShape;
}
bool						Missile::getDoesMove() const{return Missile::_doesMove;}
bool						Missile::getDoesShoot() const{return Missile::_doesShoot;}
int							Missile::getPosX(void) const{return this->_posX;}
int							Missile::getPosY(void) const{return this->_posY;}

float						Missile::getAngle(void) const{return this->_angle;}
int							Missile::getSrcX(void) const{return this->_srcX;}
int							Missile::getSrcY(void) const{return this->_srcY;}
int							Missile::getMovCD(void) const{return this->_movCD;}
// AObject                     *Missile::getThis(void){return this;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Missile::setPosX(int x){this->_posX = x;}
void						Missile::setPosY(int y){this->_posY = y;}
void						Missile::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Missile::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Missile::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
