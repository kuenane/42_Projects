// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 11:12:18 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 10:56:08 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int		main(void)
{
	SuperMutant		*sm = new SuperMutant();
	RadScorpion		*rs = new RadScorpion();
	PlasmaRifle		*pr = new PlasmaRifle();
	PowerFist		*pf = new PowerFist();
	Character		*c = new Character("Toto");
	Character		*c2 = new Character("Tata");
	
	c->attack(NULL);
	c->attack(sm);
	c->equip(pr);
	c->equip(pf);
	c->attack(rs);
	std::cout << *c;
	std::cout << *c2;

	c->attack(sm);
	c->attack(sm);
	c->attack(sm);
	c->attack(sm);
	c->attack(sm);
	c->recoverAP();
	c->attack(rs);

	return (0);
}
