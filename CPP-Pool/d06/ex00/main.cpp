// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 21:35:10 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/14 21:35:11 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Converter.hpp"

static void		ft_convert(const std::string &input)
{
	if (input.empty())
	{
		std::cout << "Invalid parameter..." << std::endl;
		return ;
	}
	Converter	converter(input);

	if (converter.detect_type())
		converter.print();
	else
		std::cout << "Invalid parameter..." << std::endl;
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_convert(static_cast<std::string>(av[1]));
	else
		std::cout << "Please enter a parameter..." << std::endl;
	return (0);
}
