// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 15:58:11 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/06 12:24:52 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include <string>
#include "PhBook.class.hpp"
#include <limits>

void	print_search_list(PhBook *phbk, int nb)
{
	int		i = -1;

	phbk[0].print_title_general();
	while (++i < nb)
		phbk[i].print_general(i);
}

void	choose_and_print_detailed(PhBook *phbk, int i)
{
	int					choice = -1;
	std::string			buf;
	std::istringstream	buf2;
	
	std::cin.clear();
	while (42)
	{
		std::cout << std::endl << "index choosen: ";
		std::getline(std::cin, buf);
		if (std::cin.eof())
			return ;
		std::cin.clear();
		buf2.str(buf);
		buf2 >> choice;
		if (choice >= 0 && choice < i)
			break;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	phbk[choice].print_detailed();
}

int		main(void)
{
	PhBook			phbk[8];
	std::string		input;
	int				i = 0;
	
	std::cout << "<--- pHoNe bOoK --->" << std::endl << std::endl;
	std::getline(std::cin, input);
	while (input.compare("EXIT") != 0 && !std::cin.eof())
	{
		if (input.compare("ADD") == 0)
		{
			if (i == 8)
				std::cout << "Can't add more contact (8 max)" << std::endl;
			else
			{
				phbk[i].fill_fields();
				i++;
			}
		}
		else if (input.compare("SEARCH") == 0)
		{
			if (i == 0)
				std::cout << "No contact found" << std::endl << std::endl;
			else
			{
				print_search_list(&phbk[0], i);
				choose_and_print_detailed(&phbk[0], i);
			}
		}
		else
			std::cout << "INPUT ERROR !! usage : [ADD/SEARCH/EXIT]" << std::endl << std::endl;
		std::getline(std::cin, input);
	}
	std::cout << std::endl << "Will now exit..." << std::endl;
	return (0);
}
