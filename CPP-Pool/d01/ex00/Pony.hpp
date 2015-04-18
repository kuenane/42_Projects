// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 14:03:48 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 12:58:33 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

#ifndef PONY_HPP
# define PONY_HPP

class Pony {

public:
	Pony(const std::string &name, int lvl);
	~Pony(void);
	void sayHello(void) const;

private:
	const std::string	_name;
	int					_lvl;

};

#endif
