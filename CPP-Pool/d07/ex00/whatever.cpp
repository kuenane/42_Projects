// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   whatever.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 22:51:16 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/02 23:26:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template<typename T>
void	swap(T &t1, T &t2)
{
	T	tmp = t1;

	t1 = t2;
	t2 = tmp;
}

template<typename T>
const T		&min(const T &t1, const T &t2)
{
	if (t1 < t2)
		return t1;
	return t2;
}

template<typename T>
const T		&max(const T &t1, const T &t2)
{
	if (t1 > t2)
		return t1;
	return t2;
}

int			main(void)
{
	int i = 42;
	int j = 21;
	char c = 'a';
	char d ='z';

	std::cout << "<<<<<----- SWAP TEMPLATE ----->>>>>" << std::endl;
	std::cout << "<int>  BEFORE i=" << i << " j=" << j << std::endl;
	::swap<int>(i, j);
	std::cout << "<int>  AFTER  i=" << i << " j=" << j << std::endl;
	std::cout << "<char> BEFORE c=" << c << "  d=" << d << std::endl;
	::swap<char>(c, d);
	std::cout << "<char> AFTER  c=" << c << "  d=" << d << std::endl << std::endl;

	std::cout << "<<<<<----- MIN TEMPLATE ----->>>>>" << std::endl;
	std::cout << "<int>  i=" << i << " j=" << j << "     return => " << ::min(i, j) << std::endl;
	std::cout << "<char> c=" << c << "  d=" << d << "      return => " << ::min(c, d) << std::endl;
	std::cout << "<int>  i=" << j << " j=" << i << "     return => " << ::min(j, i) << std::endl;
	std::cout << "<char> c=" << d << "  d=" << c << "      return => " << ::min(d, c) << std::endl;
	i = 42;
	d = 'z';
	std::cout << "<int>  i=" << i << " j=" << j << "     return => " << ::min(i, j) << std::endl;
	std::cout << "<char> c=" << c << "  d=" << d << "      return => " << ::min(c, d) << std::endl << std::endl ;

	i = 21;
	d = 'a';
	std::cout << "<<<<<----- MAX TEMPLATE ----->>>>>" << std::endl;
	std::cout << "<int>  i=" << i << " j=" << j << "     return => " << ::max(i, j) << std::endl;
	std::cout << "<char> c=" << c << "  d=" << d << "      return => " << ::max(c, d) << std::endl;
	std::cout << "<int>  i=" << j << " j=" << i << "     return => " << ::max(j, i) << std::endl;
	std::cout << "<char> c=" << d << "  d=" << c << "      return => " << ::max(d, c) << std::endl;
	i = 42;
	c = 'a';
	d = 'a';
	std::cout << "<int>  i=" << i << " j=" << j << "     return => " << ::max(i, j) << std::endl;
	std::cout << "<char> c=" << c << "  d=" << d << "      return => " << ::max(c, d) << std::endl;
	return (0);
}
