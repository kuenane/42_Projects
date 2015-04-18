// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/02 14:22:43 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/02 16:37:20 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Data{std::string s1; int n; std::string s2;};

void	*serialize(void)
{
	const char	s[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char		*toto = new char[sizeof(char) * 16 + sizeof(int)];
	int			i = -1;
	
	while (++i < 20)
		if (i < 8 || i > 11 )
			toto[i] = s[rand() % 62];
	*reinterpret_cast<int*>(toto + 8) = rand();
	return (toto);
}

Data	*deserialize(void *raw)
{
	Data	*toto = new Data;
	char	*ptr = static_cast<char*>(raw);
	
	toto->s1 = std::string(ptr, 8);
	ptr += 8;
	toto->n = *reinterpret_cast<int*>(ptr);
	ptr += sizeof(int) / sizeof(char);
	toto->s2 = std::string(ptr, 8);
	return (toto);
}

int		main(void)
{
	srand(time(NULL));
	void	*data1 = serialize();
	Data	*data11 = deserialize(data1);
	void	*data2 = serialize();
	Data	*data22 = deserialize(data2);
	void	*data3 = serialize();
	Data	*data33 = deserialize(data3);

	std::cout << "serialized 1: " << static_cast<char*>(data1) << std::endl;
	std::cout << "s1: " << data11->s1 << " n: " << data11->n << " s2: " << data11->s2 << std::endl << std::endl;
	delete static_cast<char*>(data1);
	delete data11;

	std::cout << "serialized 2: " << static_cast<char*>(data2) << std::endl;
	std::cout << "s1: " << data22->s1 << " n: " << data22->n << " s2: " << data22->s2 << std::endl << std::endl;
	delete static_cast<char*>(data2);
	delete data22;

	std::cout << "serialized 3: " << static_cast<char*>(data3) << std::endl;
	std::cout << "s1: " << data33->s1 << " n: " << data33->n << " s2: " << data33->s2 << std::endl;
	delete static_cast<char*>(data3);
	delete data33;

	return (0);
}
