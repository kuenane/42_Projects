// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 13:06:31 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:29:43 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	f1("f1");
	FragTrap	f2(f1);

	ScavTrap	s1("s1");
	ScavTrap	s2(s1);

	f1.rangedAttack("f2");
	f1.meleeAttack("f2");
	f1.takeDamage(100);
	f1.beRepaired(150);
	f1.vaulthunter_dot_exe("f2");

	s1.rangedAttack("s2");
	s1.meleeAttack("s2");
	s1.takeDamage(100);
	s1.beRepaired(150);
	s1.challengeNewcomer();

	return (0);
}
