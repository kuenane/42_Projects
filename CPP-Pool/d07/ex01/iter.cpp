// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 23:29:32 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/03 07:07:19 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template<typename T>
void	iter(T tab[], int len, void (*f)(T&))
{
	int			i = -1;
	while (++i < len)
		f(tab[i]);
}

template<typename T>
void	print_it(T &cur)
{
	std::cout << cur << " ";
}

template<typename T>
void	inc_it(T &cur)
{
	cur++;
}

int		main(void)
{
	int			tab[3] = {1, 2 ,3};
	std::cout << "<int> tab {1, 2, 3}" << std::endl << "PRINT_IT: ";
	iter<int>(tab, 3, &print_it);
	std::cout << std::endl << "INC_IT" << std::endl << "PRINT_IT: ";
	iter<int>(tab, 3, &inc_it);
	iter<int>(tab, 3, &print_it);

	std::cout << std::endl << std::endl;

	char		tab2[3] = {'a', 'd' ,'w'};
	std::cout << "<char> tab {a, d, w}" << std::endl << "PRINT_IT: ";
	iter<char>(tab2, 3, &print_it);
	std::cout << std::endl << "INC_IT" << std::endl << "PRINT_IT: ";
	iter<char>(tab2, 3, &inc_it);
	iter<char>(tab2, 3, &print_it);
	std::cout << std::endl;
	return (0);
}
