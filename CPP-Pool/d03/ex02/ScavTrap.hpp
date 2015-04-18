// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 17:14:27 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:27:15 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	ScavTrap(const std::string &name);
	ScavTrap(ScavTrap const &src);
	virtual ~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs);

	void	challengeNewcomer(void);
	void	plugChallenge(void) const;
	void	thorChallenge(void) const;
	void	zazChallenge(void) const;
	void	NSChallenge(void) const;
	void	stCardChallenge(void) const;
	
private:
	ScavTrap();

};

#endif
