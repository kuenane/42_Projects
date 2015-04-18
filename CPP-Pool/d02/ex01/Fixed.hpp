// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/16 15:15:40 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/09 06:55:22 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed(void);

	Fixed &operator=(const Fixed &rhs);
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	static const int _fbits;
	int _rbits;

};

std::ostream &operator<<(std::ostream &os, Fixed const &rhs);

#endif
