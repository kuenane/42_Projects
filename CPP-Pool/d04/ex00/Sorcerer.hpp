// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 08:58:04 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:42:39 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
#include "Victim.hpp"

class Sorcerer
{
public:

	Sorcerer(const std::string name, const std::string title);
	Sorcerer(Sorcerer const &src);
	virtual ~Sorcerer();
	Sorcerer					&operator=(Sorcerer const &rhs);

	const std::string	&getName(void) const;
	const std::string	&getTitle(void) const;

	virtual void polymorph(const Victim &vict) const;
	
protected:

private:
	std::string		_name;
	std::string		_title;

	Sorcerer();

};

std::ostream					&operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
