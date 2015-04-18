// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 16:28:23 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OfficeBlock.hpp"

int		main(void)
{
	Intern			intern;
	Bureaucrat		signing("sign", 1);
	Bureaucrat		executing("sign", 1);
	OfficeBlock		ob;
	OfficeBlock		ob2(&intern, &signing, &executing);
	std::cout << std::endl;
	try
	{
		ob2.doBureaucracy("PresidentialPardon", "titi");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Setting an intern, a signer and an executor..." << std::endl << std::endl;
	ob.setIntern(&intern);
	ob.setSigner(&signing);
	ob.setExecutor(&executing);
	try
	{
		ob.doBureaucracy("PresidentialPardon", "titi");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
