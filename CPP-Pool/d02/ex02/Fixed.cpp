// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/16 15:15:45 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/09 07:13:43 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void):_rbits(0){}

Fixed::Fixed(const Fixed &src){this->_rbits=src.getRawBits();}

Fixed::Fixed(const int nb){this->_rbits = roundf(nb * 256);}

Fixed::Fixed(const float nb){this->_rbits = roundf(nb * 256);}

Fixed::~Fixed(void){}

int Fixed::getRawBits(void) const{return (this->_rbits);}

void Fixed::setRawBits(const int raw){this->_rbits = raw;}

float Fixed::toFloat(void) const{return (this->_rbits / 256.0);}

int Fixed::toInt(void) const{return (this->_rbits / 256);}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
	os << rhs.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	this->_rbits = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &rhs)
{
	if (this->_rbits > rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &rhs)
{
	if (this->_rbits < rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &rhs)
{
	if (this->_rbits >= rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &rhs)
{
	if (this->_rbits <= rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &rhs)
{
	if (this->_rbits == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &rhs)
{
	if (this->_rbits != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->_rbits = this->_rbits + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	newfixed(*this);

	operator++();
	return (newfixed);
}

Fixed &Fixed::operator--(void)
{
	this->_rbits = this->_rbits - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	newfixed(*this);

	newfixed._rbits = newfixed._rbits - 1;
	return (newfixed);
}

Fixed const &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed const &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

const int Fixed::_fbits = 8;
