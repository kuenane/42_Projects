// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:46:31 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:54:43 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{

public:
	Peon(const std::string name);
	Peon(Peon const &src);
	virtual ~Peon();
	Peon	&operator=(Peon const &rhs);

	const std::string   &getName(void) const;

	virtual void     getPolymorphed() const;

private:
	Peon();

};

#endif
