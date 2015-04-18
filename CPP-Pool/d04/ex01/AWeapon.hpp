// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:12:08 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 09:32:32 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{

public:
	AWeapon(const std::string &name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	virtual ~AWeapon();
	AWeapon	&operator=(AWeapon const &rhs);

	const std::string	&getName() const;
	int					getAPCost() const;
	int					getDamage() const;

	virtual void	attack() const = 0;
	
protected :
	std::string			_name;
	int					_apcost;
	int					_damage;

private:

	AWeapon();
	
};

#endif
