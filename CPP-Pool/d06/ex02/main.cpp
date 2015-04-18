// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 16:52:38 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/02 18:52:53 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int		random = rand() % 3;

	if (random == 0)
		return (static_cast<Base*>(new A));
	else if (random == 1)
		return (static_cast<Base*>(new B));
	return (static_cast<Base*>(new C));
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &e){}
	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &e){}
	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &e){}
}

int		main(void)
{
	srand(time(NULL));
	Base	*ptr = generate();
	Base	*ptr2 = generate();
	Base	*ptr3 = generate();

	std::cout << "from ptr: ";
	identify_from_pointer(ptr);
	std::cout << "from ref: ";
	identify_from_reference(*ptr);

	std::cout << std::endl;
	
	std::cout << "from ptr2: ";
	identify_from_pointer(ptr2);
	std::cout << "from ref2: ";
	identify_from_reference(*ptr2);

	std::cout << std::endl;
	
	std::cout << "from ptr3: ";
	identify_from_pointer(ptr3);
	std::cout << "from ref3: ";
	identify_from_reference(*ptr3);

	return (0);
}
