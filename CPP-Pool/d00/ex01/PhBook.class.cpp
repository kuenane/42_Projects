// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhBook.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 18:25:03 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/06 12:01:32 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "PhBook.class.hpp"

PhBook::PhBook(void)
{
	return ;
}

PhBook::~PhBook(void)
{
	return ;
}

std::string PhBook::give_field(const char *msg) const
{
	std::string		newfield;

	std::cout << msg << ": ";
	std::getline(std::cin, newfield);
	return newfield;
}

void PhBook::fill_fields(void)
{
	std::cout << std::endl;
	this->_fields[0] = give_field("first name");
	this->_fields[1] = give_field("last name");
	this->_fields[2] = give_field("nickname");
	this->_fields[3] = give_field("login");
	this->_fields[4] = give_field("postal address");
	this->_fields[5] = give_field("email address");
	this->_fields[6] = give_field("phone number");
	this->_fields[7] = give_field("birthday date");
	this->_fields[8] = give_field("favorite meal");
	this->_fields[9] = give_field("underwear color");
	this->_fields[10] = give_field("darkest secret");
	std::cout << std::endl << "CONTACT ADDED :)" << std::endl << std::endl;
}

std::string PhBook::_fmt_str(std::string toformat) const
{
	std::string newstr;

		if (toformat.length() > 10)
		{
			newstr = toformat.substr(0, 9);
			newstr.insert(9, ".");
		}
		else
			newstr = toformat.substr(0, 11);
		while (newstr.length() < 10)
			newstr.insert(0, " ");
		newstr.insert(0, "|");
	return newstr;
}

void PhBook::print_title_general(void) const
{
		std::cout << std::endl << "     index|first name| last name|  nickname" << std::endl;
		std::cout << "     --------------------------------------" << std::endl;
}

void PhBook::print_general(int index) const
{
	std::cout << "         " << index << _fmt_str(this->_fields[0]) << _fmt_str(this->_fields[1]) << _fmt_str(this->_fields[2]) << std::endl;
}

void PhBook::print_detailed(void) const
{
	std::cout << std::endl << "first name: " << this->_fields[0] << std::endl;
	std::cout << "last name: " << this->_fields[1] << std::endl;
	std::cout << "nickname: " << this->_fields[2] << std::endl;
	std::cout << "login: " << this->_fields[3] << std::endl;
	std::cout << "postal address: " << this->_fields[4] << std::endl;
	std::cout << "email address: " << this->_fields[5] << std::endl;
	std::cout << "phone number: " << this->_fields[6] << std::endl;
	std::cout << "birthday date: " << this->_fields[7] << std::endl;
	std::cout << "favorite meal: " << this->_fields[8] << std::endl;
	std::cout << "underwear color: " << this->_fields[9] << std::endl;
	std::cout << "darkest secret: " << this->_fields[10] << std::endl << std::endl;
}
