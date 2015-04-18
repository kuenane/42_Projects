// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 09:22:30 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:48:39 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
public:

	Victim(const std::string name);
	Victim(Victim const &src);
	virtual ~Victim();
	Victim		&operator=(Victim const &rhs);

	const std::string	&getName(void) const;

	virtual void	 getPolymorphed() const;
	
protected:
	std::string		_name;

private:

	Victim();

};

std::ostream					&operator<<(std::ostream &o, Victim const &rhs);

#endif
