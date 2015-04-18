// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/18 20:51:07 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:28:28 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

public:

	ClapTrap(const std::string &name);
	ClapTrap(ClapTrap const &src);
	virtual ~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &rhs);

	const std::string   &getName(void) const;
	int     getHP(void) const;
	int     getMaxHP(void) const;
	int     getNRG(void) const;
	int     getMaxNRG(void) const;
	int     getLvl(void) const;
	int     getMlDamage(void) const;
	int     getRgDamage(void) const;
	int     getArmDamage(void) const;

	void    rangedAttack(const std::string &target) const;
	void    meleeAttack(const std::string &target) const;
	void    takeDamage(unsigned int amount);
	void    beRepaired(unsigned int amount);
	
protected:
	ClapTrap();

	const std::string   _name;
	int _HP;
	int _MaxHP;
	int _NRG;
	int _MaxNRG;
	int _Lvl;
	int _MlDamage;
	int _RgDamage;
	int _ArmDamage;
	
private:

};

#endif
