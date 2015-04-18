// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/14 11:17:28 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/16 10:57:21 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <sstream>

static void		replace_in_buf(std::string &buf, const std::string &s1, const std::string &s2)
{
	while (buf.find(s1) != buf.npos)
		buf.replace(buf.find(s1), s1.length(), s2);
}

static void		ft_replace(char **av, const char *outname)
{
	std::ifstream		ifs(av[1]);
	std::ofstream		ofs(outname);
	std::ostringstream	tmp;
	std::string			buf;
	const std::string	s1 = av[2];
	const std::string	s2 = av[3];

	if (!ifs)
		std::cout << "Open error" << std::endl;
	else if (!ofs)
		std::cout << "Write error" << std::endl;
	else
	{
		tmp << ifs.rdbuf();
		buf = tmp.str();
		replace_in_buf(buf, s1, s2);
		ofs << buf;
	}
	ifs.close();
	ofs.close();
}

int				main(int ac, char **av)
{
	std::string outname = ".replace";

	if (ac == 4 && av[1][0] && av[2][0] && av[3][0])
	{
		outname.insert(0, av[1]);
		ft_replace(av, outname.data());
	}
	else
		std::cout << "usage: ./replace filename s1 s2" << std::endl;
	return (0);
}
