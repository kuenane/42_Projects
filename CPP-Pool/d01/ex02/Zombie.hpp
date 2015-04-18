// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 16:12:05 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 13:02:39 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:

	Zombie(const std::string &name, const std::string &type);
	~Zombie(void);

	void announce(void) const;

private:
	const std::string	_name;
	const std::string	_type;
};

#endif
