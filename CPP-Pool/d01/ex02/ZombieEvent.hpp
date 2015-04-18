// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:08:51 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:04:32 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent {

public:

	ZombieEvent(void);
	~ZombieEvent(void);
	void setZombieType(const std::string &type);
	Zombie *newZombie(const std::string &name);
	void randomChump(void);

private:
	std::string		_Zombie_Type;
	std::string		_randannounce(int rand);
};

#endif
