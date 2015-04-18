// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/03 07:10:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/03 15:31:24 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{

public:
	Array() :
	_size(0), _arr(new T[_size])
	{
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n) :
	_size(n), _arr(new T[_size])
	{
		T	*toto = new T();

		while (n-- > 0)
		{
			_arr[n]	= *toto;
		}
		delete [] toto;
		std::cout << "u_int constructor called" << std::endl;
	}

	Array(Array<T> &src) :
		_size(0), _arr(new T[src.size()])
	{
		while (this->_size < src.size())
		{
			this->_arr[_size] = src[_size];
			this->_size++;
		}
		*this = src;
		std::cout << "Copy constructor called" << std::endl;
	}

	~Array(){delete [] this->_arr;}
	unsigned int size() const {return this->_size;}

	Array<T> &operator=(Array<T> &rhs)
	{
		delete [] this->_arr;
		this->_arr = new T[rhs.size()];
		this->_size = 0;
		while (this->_size < rhs.size())
		{
			this->_arr[_size] = rhs[_size];
			this->_size++;
		}
		std::cout << "= operator called" << std::endl;
		return *this;
	}

	T &operator[](const unsigned int n)
	{
		if (n >= this->_size)
			throw std::exception();
		return this->_arr[n];
	}

protected:

private:
	unsigned int		_size;
	T					*_arr;

};

#endif
