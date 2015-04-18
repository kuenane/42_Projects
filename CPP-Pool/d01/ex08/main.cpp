// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/01 10:24:18 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/01 10:35:56 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int		main(void)
{
	Human		human;

	human.action("meleeAttack", "toto");
	human.action("rangedAttack", "titi");
	human.action("intimidationShout", "tata");
	return (0);
}
