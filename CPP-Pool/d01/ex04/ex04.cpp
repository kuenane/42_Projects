// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:17:06 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/13 16:26:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int		main(void)
{
	std::string		string = "THIS CONTAINS 'HI THIS IS BRAIN'";
	std::string		*ptr = &string;
	std::string		&ref = string;

	std::cout << "ptr: " << *ptr << std::endl;
	std::cout << "ref: " << ref << std::endl;
	return (0);
}
