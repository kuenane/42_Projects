// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:09:13 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 18:06:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Player.class.hpp>

#define PLAYER_SPEED(B) ((B) * 7 / 4)

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Player::_mobName = "Player";
Shape const					Player::_mobShape =
	Shape(PLAYER_SHAPE1, PLAYER_COLOR, DEFAULT_COLOR);
bool const					Player::_doesMove = true;
bool const					Player::_doesShoot = true;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Player::Player(Game &g) :
	AObject(), _game(g)
{
	// std::cout << "[Player](main) Ctor called" << std::endl;
	this->setPosX(g.getMaxX() / 2);
	this->setPosY(g.getMaxY() - 5);
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Player::~Player()
{
	// std::cout << "[Player]() Dtor called" << std::endl;
	this->_game.leave_game("You died...");
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Player::getName() const{return Player::_mobName;}
Shape const					&Player::getShape() const{return Player::_mobShape;}
bool						Player::getDoesMove() const{return Player::_doesMove;}
bool						Player::getDoesShoot() const{return Player::_doesShoot;}
int							Player::getPosX(void) const{return this->_posX;}
int							Player::getPosY(void) const{return this->_posY;}
Game                        &Player::getGame(void){return this->_game;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Player::setPosX(int x){this->_posX = x;}
void						Player::setPosY(int y){this->_posY = y;}
void						Player::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Player::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Player::moveCall(Game const &g)
{
	(void)g;
	return ;
}

void						Player::moveEvent(Game const &g, int x, int y)
{
	this->_posX += PLAYER_SPEED(2 * x);
	this->_posY += PLAYER_SPEED(y);
	if (this->_posX < 4)
		this->_posX = 4;
	else if (this->_posX > g.getMaxX() - 5)
		this->_posX = g.getMaxX() - 5;
	if (this->_posY < 1)
		this->_posY = 1;
	else if (this->_posY > g.getMaxY() - 4)
		this->_posY = g.getMaxY() - 4;
	return ;
}
