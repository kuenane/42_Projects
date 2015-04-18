// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:42:19 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:00:59 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class Human {

public:
	Human(void);
	~Human(void);
	std::string	identify(void) const;
	const Brain	&getBrain(void);

private:
	Brain	_Brain;

};

#endif
