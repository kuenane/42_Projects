// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 17:47:33 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:07:39 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) : _IQ(120){}

Brain::~Brain(void){}

std::string Brain::identify(void) const
{
	std::ostringstream	oss;

	(void)_IQ;
	oss << this;
	return oss.str();
}
