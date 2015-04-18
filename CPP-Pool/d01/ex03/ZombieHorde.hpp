// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 14:49:14 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:55:39 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde(int n);
	~ZombieHorde(void);
	void announce(void) const;

private:
	int				_nbzomb;
	Zombie			*_zombtab;
};

#endif
