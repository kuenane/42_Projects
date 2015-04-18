// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:10:10 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 18:16:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Pig.class.hpp>
#include <Sheep.class.hpp>
#include <Fizzy.class.hpp>
#include <Snake.class.hpp>
#include <Centipede.class.hpp>
#include <Lombric.class.hpp>
#include <Player.class.hpp>
#include <Missile.class.hpp>

#define SIZE_MIN_X 20
#define SIZE_MIN_Y 20

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Game::Game(int maxX, int maxY) :
	objsTab(NULL), objsFriendlyTab(NULL),
	_objsTabCurChunk(0), _objsTabNextIndex(0),
	_objsFriendlyTabCurChunk(0), _objsFriendlyTabNextIndex(0),
	_maxX(maxX), _maxY(maxY)
{
//	std::cout << "[Game]() Ctor called" << std::endl;
	if (maxX < SIZE_MIN_X || maxY < SIZE_MIN_Y)
		this->leave_game("Window too small");
	this->_dstFgChars = new std::string[maxY];
	this->_dstFgColors = new char[maxY * maxX];
	this->_dstBgColors = new char[maxY * maxX];
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Game::~Game()
{
//	std::cout << "[Game]() Dtor called" << std::endl;
	delete [] this->_dstFgChars;
	delete [] this->_dstFgColors;
	delete [] this->_dstBgColors;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
int							Game::getMaxX(void) const{return this->_maxX;}
int							Game::getMaxY(void) const{return this->_maxY;}
std::string					*Game::getDstFgChars(void) const
{return this->_dstFgChars;}
char						*Game::getDstFgColors(void) const
{return this->_dstFgColors;}
char						*Game::getDstBgColors(void) const
{return this->_dstBgColors;}
size_t						Game::getObjsTabNextIndex(void) const
{return this->_objsTabNextIndex;}
size_t						Game::getObjsFriendlyTabNextIndex(void) const
{return this->_objsFriendlyTabNextIndex;}

// **************************************************** SETTERS *** SETTERS * //
void						Game::setFgChar(int x, int y, char c) const
{this->_dstFgChars[y][x] = c;}
void						Game::setFgColor(int x, int y, char c) const
{this->_dstFgColors[y * this->_maxX + x] = c;}
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Game::leave_game(std::string msg)
{
	clear();
	refresh();
	endwin();
	std::cout << msg << std::endl;
	exit(0);
}

void						Game::keyboard_input(void)
{
	int			key;
	Player		&p = static_cast<Player&>(*this->objsFriendlyTab[0]);

	key = getch();
	if (key == 'Q' || key == 'q')
		this->leave_game("Exit in the game...");
	else if (key == KEY_UP)
		p.moveEvent(*this, 0, -1);
	else if (key == KEY_DOWN)
		p.moveEvent(*this, 0, 1);
	else if (key == KEY_LEFT)
		p.moveEvent(*this, -1, 0);
	else if (key == KEY_RIGHT)
		p.moveEvent(*this, 1, 0);
	else if (key == ' ')
	{
		
		popMissileFriendly(&p, 3.14159 - 3.14159 / 20, CLOCKS_PER_SEC / 100);
		popMissileFriendly(&p, 3.14159 + 3.14159 / 20, CLOCKS_PER_SEC / 100);
		popMissileFriendly(&p, 3.14159 - 3.14159 / 40, CLOCKS_PER_SEC / 100);
		popMissileFriendly(&p, 3.14159 + 3.14159 / 40, CLOCKS_PER_SEC / 100);
		popMissileFriendly(&p, 3.14159, CLOCKS_PER_SEC / 100);
	}
	else if (key == 'u' || key == 'U')
	{
		for (int i = 0; i < (int)this->_objsTabNextIndex;)
		{
			AObject	*ob = this->objsTab[i];

			this->objRemove(i);
			delete ob;
		}
	}
}

void						Game::putImage(void) const
{
	char		prevColorPair = 0;
	const char	*line;
	int			cur_index;
	int			curColorPair;
	
	for (int i = 0; i < this->_maxY; i++)
	{
		line = this->_dstFgChars[i].c_str();
		for (int j = 0; j < this->_maxX; j++)
		{
			cur_index = i * this->_maxX + j;
			curColorPair = (this->_dstBgColors[cur_index] << 4) +
				this->_dstFgColors[cur_index];
			if (curColorPair != prevColorPair)
				attron(COLOR_PAIR(curColorPair));
			printw("%c", line[j]);
			prevColorPair = curColorPair;
		}
	}
	return ;
}

void						Game::putObjects(void) const
{
	for (int i = 0; i < (int)this->_objsTabNextIndex;i++)
		(void)this->objsTab[i]->getShape().
			putShape(*this, this->objsTab[i]->getPosX(), this->objsTab[i]->getPosY());
	for (int i = 0; i < (int)this->_objsFriendlyTabNextIndex;i++)
		(void)this->objsFriendlyTab[i]->getShape().
			putShape(*this, this->objsFriendlyTab[i]->getPosX(), this->objsFriendlyTab[i]->getPosY());
	return ;
}

static int					randomizeXStart(Shape const &s, int maxX)
{
	maxX -= s.getLeftSize() - s.getRightSize();
	maxX = std::rand() % maxX;
	return (maxX + s.getLeftSize());
} 

void						Game::popSheep(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Sheep();
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		this->objAdd(o);
	}
	return ;
}

void						Game::popPig(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Pig();
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		o->setPosY(std::rand() % (this->_maxY / 3) +
				   o->getShape().getTopSize());
		this->objAdd(o);
	}
	return ;
}

void						Game::popLombric(int count)
{
	AObject		*o;
	
	for (; count > 0; count--)
	{
		o = new Lombric();
		Shape const	&s = o->getShape();
		o->setPosX(randomizeXStart(s, this->_maxX / 7 * 5) + this->_maxX / 7);
		o->setPosY(s.getTopSize() - 1);
		this->objAdd(o);
	}
	return ;
}

void						Game::popMissile(AObject const *shooter, float angle,
											 clock_t movCD)
{
	AObject		*o;

	o = new Missile(angle, shooter->getPosX(), shooter->getPosY() + 1, movCD);
	o->setPosX(shooter->getPosX());
	o->setPosY(shooter->getPosY() + 1);
	this->objAdd(o);
	return ;
}

void						Game::popMissileFriendly(AObject const *shooter, float angle,
													 clock_t movCD)
{
	AObject		*o;

	angle += 0.025 - ((float)(std::rand() % 5) / 100.);
	o = new Missile(angle, shooter->getPosX(), shooter->getPosY() - 1, movCD);
	o->setPosX(shooter->getPosX());
	o->setPosY(shooter->getPosY() - 1);
	this->objFriendlyAdd(o);
	return ;
}

void						Game::popSnake(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Snake();
		Shape const	&s = o->getShape();
		o->setPosX(randomizeXStart(s, this->_maxX * 4 / 5) +
				   this->_maxX / 10);
		o->setPosY(s.getTopSize());
		this->objAdd(o);
	}
	return ;
}

void						Game::popCentipede(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Centipede();
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
	this->objAdd(o);
	}
	return ;
}

void						Game::popFizzy(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Fizzy();
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
	this->objAdd(o);
	}
	return ;
}

void                        Game::objAdd(AObject *ob)
{
	if (this->_objsTabNextIndex >= this->_objsTabCurChunk)
	{
		AObject	**tmp = new AObject*[this->_objsTabCurChunk + OBJS_TAB_DELTA];

		for (size_t i = 0; i < this->_objsTabNextIndex;i++)
			tmp[i] = this->objsTab[i];
		if (this->_objsTabCurChunk > 0)
			delete [] this->objsTab;
		this->objsTab = tmp;
		this->_objsTabCurChunk += OBJS_TAB_DELTA;
	}
	this->objsTab[this->_objsTabNextIndex++] = ob;
	return ;
}

void                        Game::objRemove(size_t index)
{
	this->_objsTabNextIndex--;
	if (index == this->_objsTabNextIndex)
		this->objsTab[index] = NULL;
	else
		this->objsTab[index] = this->objsTab[this->_objsTabNextIndex];
}

void                        Game::objFriendlyAdd(AObject *ob)
{
	if (this->_objsFriendlyTabNextIndex >= this->_objsFriendlyTabCurChunk)
	{
		AObject	**tmp = new AObject*[this->_objsFriendlyTabCurChunk + OBJS_TAB_DELTA];

		for (size_t i = 0; i < this->_objsFriendlyTabNextIndex;i++)
			tmp[i] = this->objsFriendlyTab[i];
		if (this->_objsFriendlyTabCurChunk > 0)
			delete [] this->objsFriendlyTab;
		this->objsFriendlyTab = tmp;
		this->_objsFriendlyTabCurChunk += OBJS_TAB_DELTA;
	}
	this->objsFriendlyTab[this->_objsFriendlyTabNextIndex++] = ob;
	return ;
}

void                        Game::objFriendlyRemove(size_t index)
{
	this->_objsFriendlyTabNextIndex--;
	if (index == this->_objsFriendlyTabNextIndex)
		this->objsFriendlyTab[index] = NULL;
	else
		this->objsFriendlyTab[index] =
			this->objsFriendlyTab[this->_objsFriendlyTabNextIndex];
}
