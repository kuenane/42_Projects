// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:12:05 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/13 16:03:51 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie(void);
	~Zombie(void);

	void announce(void) const;

private:

	std::string		_type;
	std::string		_name;
};

#endif
