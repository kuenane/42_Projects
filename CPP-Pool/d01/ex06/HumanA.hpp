// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/14 09:52:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:19:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA(void);
	void attack(void) const;

private:
	std::string _name;
	Weapon &_weapon;

};

#endif
