// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:37:45 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 14:45:11 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:

	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &src);
	virtual ~PlasmaRifle();
	PlasmaRifle					&operator=(PlasmaRifle const &rhs);

	virtual void    attack() const;

protected:

private:

};

#endif
