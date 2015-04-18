// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 07:10:45 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/03 15:32:19 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.hpp"

int		main(void)
{
	std::cout << "Create an Array with default constructor:" << std::endl;
	Array<int>	*toto = new Array<int>();
	std::cout << std::endl << "Create an Array with u_int constructor :" << std::endl;
	Array<int>	*tata = new Array<int>(10);
	std::cout << std::endl << "Create an Array with copy constructor:" << std::endl;
	Array<int>	*titi = new Array<int>(*tata);
	std::cout << std::endl;

	std::cout << "<toto> {0}  Call size function: " << toto->size() << std::endl;
	std::cout << "<tata> {10} Call size function: " << tata->size() << std::endl;
	std::cout << "<titi> {10} Call size function: " << titi->size() << std::endl;

	std::cout << std::endl << "Call operator = (*tata = *titi):" << std::endl;
	*tata = *toto;

	std::cout << std::endl << "titi[1] = " << (*titi)[1] << std::endl;

	std::cout << std::endl << "Assign 42 to titi[1]" << std::endl;
	(*titi)[1] = 42;

	std::cout << std::endl << "titi[1] = " << (*titi)[1] << std::endl;

	delete toto;
	delete tata;
	delete titi;
	return (0);
}
