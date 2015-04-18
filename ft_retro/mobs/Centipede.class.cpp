// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Centipede.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:02:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 12:14:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Centipede.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Centipede::_mobName = "Centipede";
Shape const					Centipede::_mobShape =
	Shape(CENTIPEDE_SHAPE, CENTIPEDE_COLOR, DEFAULT_COLOR);
bool const					Centipede::_doesMove = true;
bool const					Centipede::_doesShoot = true;
clock_t const				Centipede::_moveCD = CLOCKS_PER_SEC / 5;
int const					Centipede::_moveChancesFactor = 1000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Centipede::Centipede() :
	AObject(), AMovPatternSheep(Centipede::_moveCD, Centipede::_moveChancesFactor),
	AShootPatternDefault(1, CLOCKS_PER_SEC / 2, 100, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Centipede](main) Ctor called" << std::endl;
	return ;
}

Centipede::Centipede(Centipede const &src) :
	AObject(), AMovPatternSheep(Centipede::_moveCD, Centipede::_moveChancesFactor),
	AShootPatternDefault(1, CLOCKS_PER_SEC / 2, 100, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Centipede](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Centipede::~Centipede()
{
	// std::cout << "[Centipede]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Centipede::getName() const{return Centipede::_mobName;}
Shape const					&Centipede::getShape() const{return Centipede::_mobShape;}
bool						Centipede::getDoesMove() const{return Centipede::_doesMove;}
bool						Centipede::getDoesShoot() const{return Centipede::_doesShoot;}
int							Centipede::getPosX(void) const{return this->_posX;}
int							Centipede::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Centipede::setPosX(int x){this->_posX = x;}
void						Centipede::setPosY(int y){this->_posY = y;}
void						Centipede::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Centipede::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Centipede::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}

void						Centipede::shootCall(Game &g)
{
	this->tryShoot(g);
	return ;
}
