// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 22:15:32 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:36:21 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap
{

public:
	NinjaTrap(const std::string &name);
	NinjaTrap(NinjaTrap const &src);
	virtual ~NinjaTrap(void);
	NinjaTrap &operator=(NinjaTrap const &rhs);

	void	ninjaShoebox(FragTrap &src) const;
	void	ninjaShoebox(ScavTrap &src) const;
	void	ninjaShoebox(NinjaTrap &src) const;

private:
	NinjaTrap();

};

#endif
