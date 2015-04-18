// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 09:59:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 14:11:57 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Snake.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Snake::_mobName = "Snake";
Shape const					Snake::_mobShape =
	Shape(SNAKE_SHAPE, SNAKE_COLOR, DEFAULT_COLOR);
bool const					Snake::_doesMove = true;
bool const					Snake::_doesShoot = true;
clock_t const				Snake::_moveCD = CLOCKS_PER_SEC / 8;
int const					Snake::_moveChancesFactor = 150;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Snake::Snake() :
	AObject(), AMovPatternSheep(Snake::_moveCD, Snake::_moveChancesFactor),
	AShootPatternDefault(3, CLOCKS_PER_SEC * 3 / 2, 1000, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Snake](main) Ctor called" << std::endl;
	return ;
}

Snake::Snake(Snake const &src) :
	AObject(), AMovPatternSheep(Snake::_moveCD, Snake::_moveChancesFactor),
	AShootPatternDefault(3, CLOCKS_PER_SEC * 3 / 2, 1000, CLOCKS_PER_SEC / 30)
{
	// std::cout << "[Snake](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Snake::~Snake()
{
	// std::cout << "[Snake]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Snake::getName() const{return Snake::_mobName;}
Shape const					&Snake::getShape() const{return Snake::_mobShape;}
bool						Snake::getDoesMove() const{return Snake::_doesMove;}
bool						Snake::getDoesShoot() const{return Snake::_doesShoot;}
int							Snake::getPosX(void) const{return this->_posX;}
int							Snake::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Snake::setPosX(int x){this->_posX = x;}
void						Snake::setPosY(int y){this->_posY = y;}
void						Snake::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Snake::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Snake::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}

void						Snake::shootCall(Game &g)
{
	this->tryShoot(g);
	return ;
}
