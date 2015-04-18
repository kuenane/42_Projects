// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:56:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 14:45:00 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POWERRIFLE_HPP
# define POWERRIFLE_HPP

# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:

	PowerFist();
	PowerFist(PowerFist const &src);
	virtual ~PowerFist();
	PowerFist					&operator=(PowerFist const &rhs);

	virtual void    attack() const;

protected:

private:

};

#endif
