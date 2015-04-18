// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 16:12:08 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 10:43:11 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type) :
	_hp(hp), _type(type)
{
}

Enemy::Enemy(Enemy const &src) :
	_hp(src.getHp()), _type(src.getType())
{
}

Enemy::~Enemy()
{
}

Enemy						&Enemy::operator=(Enemy const &rhs)
{
	this->_hp = rhs.getHp();
	this->_type = rhs.getType();
	return (*this);
}

const std::string			&Enemy::getType(void) const{return this->_type;}
int							Enemy::getHp(void) const{return this->_hp;}

void						Enemy::takeDamage(int dmg)
{
	if (dmg > 0)
	{
		this->_hp -= dmg;
		if (this->_hp <= 0)
			this->_hp = 0;
	}
}
