// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:50 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 15:44:44 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"

int		main(void)
{
	Intern	intern;
	Form	*toto;
	Form	*tata;
	Form	*titi;

	toto = intern.makeForm("   PrEsiDential	PaRdoN", "Bender");
	std::cout << std::endl;
	tata = intern.makeForm("   RObotoMy	RequEst", "Bender");
	std::cout << std::endl;
	titi = intern.makeForm("sHrUbbEryCREATION", "Bender");
	std::cout << std::endl;
	try
	{
		intern.makeForm("toto", "Bender");
	}
	catch(Intern::FormDoesNotExist &e)
	{
		std::cout << "Catch: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete toto;
	delete tata;
	delete titi;
	return (0);

}
