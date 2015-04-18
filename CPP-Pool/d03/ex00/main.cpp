// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 13:06:31 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 10:27:33 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	toto1("toto1");
	FragTrap	toto2(toto1);

	toto1.rangedAttack("toto2");
	toto1.meleeAttack("toto2");
	toto1.takeDamage(100);
	toto1.beRepaired(150);
	toto1.vaulthunter_dot_exe("toto2");
	return (0);
}
