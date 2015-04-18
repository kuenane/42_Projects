// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:43:34 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/13 14:38:24 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent	event;
	Zombie		*toto;

	event.setZombieType("toto");
	toto = event.newZombie("new");
	toto->announce();
	delete toto;
	event.randomChump();
	return (0);
}
