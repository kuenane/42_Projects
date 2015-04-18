// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 20:03:31 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/13 20:03:31 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() {}

void			Span::addNumber(int nb) throw(std::exception)
{
	if (this->_vec.size() == this->_n)
		throw std::exception();
	this->_vec.push_back(nb);
}

void			Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) throw(std::exception)
{
	try
	{
		while (begin != end)
		{
			this->addNumber(*begin);
			begin++;
		}
	}
	catch (std::exception &e){throw std::exception();}
}

unsigned int	Span::_giveSpan(int a, int b) const
{
	if (a > b)
		return (a - b);
	return (b - a);
}

unsigned int	Span::shortestSpan(void) const throw(std::exception)
{
	if (this->_vec.size() <= 1)
		throw std::exception();

	std::vector<int>::const_iterator	it = this->_vec.begin() + 1;
	unsigned int						sp = this->_giveSpan(*(it - 1), *it);

	while (it != this->_vec.end())
	{
		if (this->_giveSpan(*(it - 1), *it) < sp)
			sp = this->_giveSpan(*(it - 1), *it);
		it++;
	}
	return (sp);
}

unsigned int	Span::longestSpan(void) const throw(std::exception)
{
	if (this->_vec.size() <= 1)
		throw std::exception();

	std::vector<int>::const_iterator	it = this->_vec.begin() + 1;
	unsigned int						sp = this->_giveSpan(*(it - 1), *it);

	while (it != this->_vec.end())
	{
		if (this->_giveSpan(*(it - 1), *it) > sp)
			sp = this->_giveSpan(*(it - 1), *it);
		it++;
	}
	return (sp);
}
