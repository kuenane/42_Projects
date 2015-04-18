// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:59:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 11:37:45 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Pig.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Pig::_mobName = "Pig";
Shape const					Pig::_mobShape =
	Shape(PIG_SHAPE, DEFAULT_COLOR, DEFAULT_COLOR);
bool const					Pig::_doesMove = true;
bool const					Pig::_doesShoot = true;
clock_t const				Pig::_moveCD = CLOCKS_PER_SEC / 10;
int const					Pig::_moveChancesFactor = 1000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Pig::Pig() :
	AObject(), AMovPatternDefault(Pig::_moveCD, Pig::_moveChancesFactor),
	AShootPatternDefault(1, CLOCKS_PER_SEC * 2, 2000, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Pig](main) Ctor called" << std::endl;
	return ;
}

Pig::Pig(Pig const &src) :
	AObject(), AMovPatternDefault(Pig::_moveCD, Pig::_moveChancesFactor),
	AShootPatternDefault(1, CLOCKS_PER_SEC * 2, 2000, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Pig](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Pig::~Pig()
{
	// std::cout << "[Pig]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Pig::getName() const{return Pig::_mobName;}
Shape const					&Pig::getShape() const{return Pig::_mobShape;}
bool						Pig::getDoesMove() const{return Pig::_doesMove;}
bool						Pig::getDoesShoot() const{return Pig::_doesShoot;}
int							Pig::getPosX(void) const{return this->_posX;}
int							Pig::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Pig::setPosX(int x){this->_posX = x;}
void						Pig::setPosY(int y){this->_posY = y;}
void						Pig::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void                        Pig::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Pig::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
void						Pig::shootCall(Game &g)
{
	this->tryShoot(g);
	return ;
}
