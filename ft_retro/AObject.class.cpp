// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:33:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 16:29:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <AObject.class.hpp>
#include <iostream>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AObject::AObject() :
	next(NULL), _posX(0), _posY(0), _deleteObject(false)
{
//	std::cout << "[AObject](main) Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AObject::~AObject()
{
//	std::cout << "[AObject]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
std::ostream				&operator<<(std::ostream &o, AObject const &rhs)
{	
	o << "[";
	o << rhs.getName();
	o << "] {";
	o << rhs.getPosX();
	o << ", ";
	o << rhs.getPosY();
	o << "}";
	return (o);
}

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
int							AObject::getPosX(void) const{return this->_posX;}
int							AObject::getPosY(void) const{return this->_posY;}
bool						AObject::getDeleteObject(void) const
{return this->_deleteObject;}

// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						AObject::setPosX(int x){this->_posX = x;}
void						AObject::setPosY(int y){this->_posY = y;}
void						AObject::setDeleteObject(bool state)
{this->_deleteObject = state;}
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						AObject::shootCall(Game &g)
{
	(void)g;
	return ;
}
bool						AObject::doesCollide(AObject const &foe, int deltaX,
												 int deltaY) const
{
	int				minMaxes[8];
	Shape const		&thisShape = this->getShape();
	Shape const		&foeShape = foe.getShape();

	//phase1
	minMaxes[2] =
		MAX(this->getPosY() - thisShape.getTopSize(),
			foe.getPosY() - foeShape.getTopSize()) - deltaY;
	minMaxes[3] =
		MIN(this->getPosY() + thisShape.getBottomSize(),
			foe.getPosY() + foeShape.getBottomSize()) + deltaY;
	if (minMaxes[2] <= minMaxes[3])
	{
		//phase2
		minMaxes[0] =
			MAX(this->getPosX() - thisShape.getLeftSize(),
				foe.getPosX() - foeShape.getLeftSize()) - deltaX;
		minMaxes[1] =
			MIN(this->getPosX() + thisShape.getRightSize(),
				foe.getPosX() + foeShape.getRightSize()) + deltaX;
		if (minMaxes[0] <= minMaxes[1])
		{
			//phase3
			// minMaxes[4] = minMaxes[0] - foe.getPosX();
			// minMaxes[0] = minMaxes[0] - this->getPosX();

			// minMaxes[5] = minMaxes[1] - foe.getPosX();
			// minMaxes[1] = minMaxes[1] - this->getPosX();

			// minMaxes[6] = minMaxes[2] - foe.getPosY();
			// minMaxes[2] = minMaxes[2] - this->getPosY();

			// minMaxes[7] = minMaxes[3] - foe.getPosY();
			// minMaxes[3] = minMaxes[3] - this->getPosY();
			if (thisShape.doesCollide(foeShape, minMaxes))
				return (true);
		}
	}
	return (false);
}

bool						AObject::doesCollideAny(Game &g) const
{
	AObject *ob;
	
	for (size_t i = 0; i < g.getObjsFriendlyTabNextIndex(); i++)
	{
		ob = g.objsFriendlyTab[i];
		if (this->doesCollide(*ob, i == 0 ? 0 : 1, 0))
		{
			g.objFriendlyRemove(i);
			delete ob;
			return (true);
		}
	}
	return (false);
}
