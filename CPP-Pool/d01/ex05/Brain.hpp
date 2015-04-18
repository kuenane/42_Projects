// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 17:47:52 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:01:38 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

public:
	Brain(void);
	~Brain(void);
	std::string	identify(void) const;

private:
	int		_IQ;

};

#endif
