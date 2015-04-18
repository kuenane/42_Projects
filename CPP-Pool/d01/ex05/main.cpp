// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:35:04 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:10:36 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int main()
{
	Human bob;
	std::cout << std::endl;
	std::cout << "Real address: " << std::endl;
	std::cout << bob.identify() << std::endl << std::endl;
	std::cout << "getBrain address: " << std::endl;
	std::cout << bob.getBrain().identify() << std::endl << std::endl;
}

