// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/12 08:29:15 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 19:55:12 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

# include <map>
# include <set>
# include <deque>
# include <vector>
# include <list>

template <typename T>
void easyfind(T icontainer, int tosearch)
{
	if (std::find(icontainer.begin(), icontainer.end(), tosearch) == icontainer.end())
		std::cout << "Not founded..." << std::endl;
	else
		std::cout << "Founded !!" << std::endl;
}

template <typename T>
void easyfind(std::map<T, int> icontainer, int tosearch)
{
	typename std::map<T, int>::iterator it = icontainer.begin();

	while (it != icontainer.end())
	{
		if (it->second == tosearch)
		{
			std::cout << "Founded !!" << std::endl;
			return ;
		}
		it++;
	}
	std::cout << "Not founded..." << std::endl;
}

#endif
