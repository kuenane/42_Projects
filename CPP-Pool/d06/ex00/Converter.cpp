// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 21:45:49 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/15 10:05:12 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Converter.hpp"

Converter::Converter(const std::string &input) : _input(input), _type(0) {}

Converter::~Converter() {}

bool				Converter::detect_type(void)
{
	this->_search_char();
	this->_search_int();
	this->_search_double();
	this->_search_float();
	if (this->_type)
		return this->_type;
	return 0;
}

void				Converter::_search_char(void)
{
	if (this->_type)
		return ;	
	if (this->_input.size() == 1 && isprint(this->_input[0]))
	{
		if (isdigit(this->_input[0]))
			this->_type = 'i';
		else
			this->_type = 'c';
	}
	if (this->_input == "\n" || this->_input == "\t")
		this->_type = 'c';
}

void				Converter::_search_int(void)
{
	if (this->_type)
		return ;
	int 	i = 0;
	if (this->_input[i] == '+' || this->_input[i] == '-')
		i++;
	if (this->_input.find_first_not_of("0123456789", i) == std::string::npos)
	{
		long	lg = strtol(this->_input.c_str(), NULL, 10);
		if (lg >= INT_MIN && lg <= INT_MAX)
			this->_type = 'i';
	}
}

void				Converter::_search_double(void)
{
	if (this->_type)
		return ;
	if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan" || this->_input == "0.0")
	{
		this->_type = 'd';
		return;
	}
	int 	i = 0;
	if (this->_input[i] == '+' || this->_input[i] == '-')
		i++;
	while (isdigit(this->_input[i]))
		i++;
	if (this->_input[i] != '.')
		return;
	if (!isdigit(this->_input[++i]))
		return;
	i++;
	while (isdigit(this->_input[i]) && i < static_cast<int>(this->_input.size()))
		i++;
	if (static_cast<int>(this->_input.size()) != i)
		return;
	double		db = strtod(this->_input.c_str(), NULL);
	if (db != 0.0 && db != HUGE_VAL)
		this->_type = 'd';
}

void				Converter::_search_float(void)
{
	if (this->_type)
		return ;
	if (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf" || this->_input == "0.0f")
	{
		this->_type = 'f';
		return;
	}
	std::string tmp = this->_input;
	std::istringstream	iss;
	float 				f;
	if (tmp[tmp.length() - 1] == 'f')
		tmp.resize(tmp.length() - 1);
	if (tmp.find('.') == std::string::npos ||
		tmp.find_first_of('.') != tmp.find_last_of('.'))
		return;
	if (tmp.find_first_not_of("0123456789.", 1) != std::string::npos ||
		tmp.find_first_not_of("0123456789.+-") != std::string::npos)
	iss.str(tmp);
	iss.clear();
	iss >> f;
	if (!iss.fail())
		return;
	this->_type = 'f';
}

void				Converter::print(void)
{
	if (this->_type == 'c')
		this->_print_char();
	else if (this->_type == 'i')
		this->_print_int();
	else if (this->_type == 'd')
		this->_print_double();
	else if (this->_type == 'f')
		this->_print_float();
}

void				Converter::_print_char(void)
{
	int 			i;
	float			f;
	double 			d;

	std::cout << "char: ";
	if (isprint(this->_input[0]))
		std::cout << "'" << this->_input[0] << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	try {i = static_cast<int>(this->_input[0]); std::cout << i << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "float: ";
	try {f = static_cast<float>(this->_input[0]); std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "double: ";
	try {d = static_cast<double>(this->_input[0]); std::cout << std::fixed << std::setprecision(1) << d << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
}

void				Converter::_print_int(void)
{
	long			lg = strtol(this->_input.c_str(), NULL, 10);
	char			c;
	float			f;
	double 			d;

	std::cout << "char: ";
	try {c = static_cast<char>(lg);	if (isprint(c) && lg >= 0 && lg <= 127) std::cout << "'" << c << "'" << std::endl; else std::cout << "Non displayable" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "int: ";
	std::cout << std::dec << this->_input << std::endl;
	std::cout << "float: ";
	try {f = static_cast<float>(lg); std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "double: ";
	try {d = static_cast<double>(lg); std::cout << std::fixed << std::setprecision(1) << d << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
}

void				Converter::_print_double(void)
{
	double			db = strtod(this->_input.c_str(), NULL);
	char			c;
	int 			i;
	float			f;
	
	std::cout << "char: ";
	try {c = static_cast<char>(db);	if (isprint(c) && db >= 0.0 && db <= 127.0) std::cout << "'" << c << "'" << std::endl; else std::cout << "Non displayable" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "int: ";
	try {if (db > INT_MAX || db < INT_MIN) throw std::bad_cast(); i = static_cast<int>(db); std::cout << i << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}


	std::cout << "float: ";
	try {f = static_cast<float>(db); std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "double: ";
	try {std::cout << std::fixed << std::setprecision(1) << db << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
}

void				Converter::_print_float(void)
{
	double				db = strtod(this->_input.c_str(), NULL);
	char				c;
	int 				i;
	float				f;

	std::cout << "char: ";
	try {c = static_cast<char>(db);	if (isprint(c) && db >= 0.0 && db <= 127.0) std::cout << "'" << c << "'" << std::endl; else std::cout << "Non displayable" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
	std::cout << "int: ";
	try {if (db > INT_MAX || db < INT_MIN) throw std::bad_cast(); i = static_cast<int>(db); std::cout << i << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}

	std::cout << "float: ";
//	std::cout << this->_input << std::endl;
	try {f = static_cast<float>(db); std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}

	std::cout << "double: ";
	try {std::cout << std::fixed << std::setprecision(1) << db << std::endl;} catch (std::bad_cast){std::cout << "impossible" << std::endl;}
//	tmp.resize(tmp.length() - 1);
//	std::cout << tmp << std::endl;
}
