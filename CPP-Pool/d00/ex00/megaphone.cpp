// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 14:39:49 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/10 15:23:24 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int		main(int ac, char **av)
{
	int		i = 1;
	int		j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[i])
    {
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] -= 32;
			std::cout << av[i][j];
			j++;
		}
		i++;
    }
	std::cout << std::endl;
	return (0);
}
