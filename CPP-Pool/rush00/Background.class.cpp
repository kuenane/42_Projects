// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 14:14:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 11:29:58 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Background.class.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
// #include <ncurses.h>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Background::Background(int x, int y, Game &g) :
	_phase(0), _x(x), _y(y), _g(g)
{
	std::string		*lines;
	char			*linesFgColors;
	char			*linesBgColors;
	
//	std::cout << "[Background](main) Ctor called" << std::endl;
	lines = new std::string[y]; //try catch ici
	linesFgColors = new char[x * y]; //try catch ici
	linesBgColors = new char[x * y]; //try catch ici
	for (int i = 0; i < y; i++)
	{
		lines[i].resize(x);
		for (int j = 0; j < x; j++)
		{

			linesFgColors[j + i * x] = 6;
			if (std::rand() % 100 <= 15)
			{
				linesBgColors[j + i * x] = 1;
				lines[i][j] = ' ';
			}
			else
			{
				linesBgColors[j + i * x] = 0;
				lines[i][j] = ' ';
			}
		}
	}
	this->_lines = lines;
	this->_linesFgColors = linesFgColors;
	this->_linesBgColors = linesBgColors;
	this->_dstFgChars = g.getDstFgChars();
	this->_dstFgColors = g.getDstFgColors();
	this->_dstBgColors = g.getDstBgColors();
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Background::~Background()
{
//	std::cout << "[Background]() Dtor called" << std::endl;
	delete [] this->_lines;
	delete [] this->_linesFgColors;
	delete [] this->_linesBgColors;
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
void						Background::putBackground(void)
{
	for (int i = 0; i < this->_y ; i++)
	{
		_dstFgChars[i] = this->_lines[(i + this->_phase) % this->_y];
		std::memcpy(this->_dstFgColors + i * this->_x,
					this->_linesFgColors + ((i + this->_phase) % this->_y) *
					this->_x,
					this->_x);
		std::memcpy(this->_dstBgColors + i * this->_x,
					this->_linesBgColors + ((i + this->_phase) % this->_y) *
					this->_x,
					this->_x);
	}
	this->_phase--;
	if (this->_phase < 0)
		this->_phase = this->_y - 1;
	return ;
}
