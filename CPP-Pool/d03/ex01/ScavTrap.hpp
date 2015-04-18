// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 17:14:27 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:17:45 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{

public:
	ScavTrap(const std::string &name);
	ScavTrap(ScavTrap const &src);
	virtual ~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &rhs);

	const std::string	&getName(void) const;
	int		getHP(void) const;
	int		getMaxHP(void) const;
	int		getNRG(void) const;
	int		getMaxNRG(void) const;
	int		getLvl(void) const;
	int		getMlDamage(void) const;
	int		getRgDamage(void) const;
	int		getArmDamage(void) const;

	void	rangedAttack(const std::string &target) const;
	void	meleeAttack(const std::string &target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	challengeNewcomer(void);
	void	plugChallenge(void) const;
	void	thorChallenge(void) const;
	void	zazChallenge(void) const;
	void	NSChallenge(void) const;
	void	stCardChallenge(void) const;
	
private:
	ScavTrap();

	const std::string	_name;
	int	_HP;
	int	_MaxHP;
	int	_NRG;
	int	_MaxNRG;
	int	_Lvl;
	int	_MlDamage;
	int	_RgDamage;
	int	_ArmDamage;
	
};

#endif
