// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/12 14:03:53 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/12 15:20:08 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

static void		ponyOnTheHeap(std::string name, int lvl)
{
	Pony	*newpony = new Pony(name, lvl);

	newpony->sayHello();
	delete newpony;
}

static void		ponyOnTheStack(std::string name, int lvl)
{
	Pony	newpony(name, lvl);

	newpony.sayHello();
}

int				main(void)
{
	std::cout << "Call Pony from the heap" << std::endl;
	ponyOnTheHeap("Pony1", 1);
	std::cout << "Call Pony from the stack" << std::endl;
	ponyOnTheStack("Pony2", 5);
}
