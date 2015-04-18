// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:56:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 09:34:57 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:

	Character(const std::string &name);
	Character(Character const &src);
	virtual ~Character();
	Character					&operator=(Character const &rhs);

	void						recoverAP();
	void						equip(AWeapon *src);
	void						attack(Enemy *dst);

	const std::string			&getName(void) const;
	int							getAP(void) const;
	AWeapon						*getWeapon(void) const;

private:
	Character();

	std::string		_name;
	int				_AP;
	AWeapon			*_Weapon;
	
};

std::ostream	&operator<<(std::ostream &o, const Character &rhs);

#endif
