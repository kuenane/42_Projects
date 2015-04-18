// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/14 09:33:49 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:17:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(const std::string &type);
	~Weapon(void);
	void setType(const std::string &type);
	const std::string &getType(void) const;

private:
	std::string	_type;
};

#endif
