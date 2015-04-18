// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 15:16:46 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:13:38 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{

public:
	FragTrap(const std::string &name);
	FragTrap(FragTrap const &src);
	virtual ~FragTrap(void);
	FragTrap &operator=(FragTrap const &rhs);

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
	void	vaulthunter_dot_exe(std::string const &target);
	void	plugAttack(std::string const &target) const;
	void	thorAttack(std::string const &target) const;
	void	zazAttack(std::string const &target) const;
	void	NSAttack(std::string const &target) const;
	void	stCardAttack(std::string const &target) const;
	
private:
	const std::string	_name;
	int	_HP;
	int	_MaxHP;
	int	_NRG;
	int	_MaxNRG;
	int	_Lvl;
	int	_MlDamage;
	int	_RgDamage;
	int	_ArmDamage;
	
	FragTrap();
};

#endif
