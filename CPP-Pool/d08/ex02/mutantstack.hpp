// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 11:53:45 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/14 11:53:46 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <iterator> 
# include <stack>

/******************************************************************************/
/******************************** HPP *****************************************/
/******************************************************************************/

template <typename T> 
class MutantStack : public std::stack<T>
{

public:
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T> &src);
		~MutantStack<T>();
		MutantStack<T> &operator=(const MutantStack<T> &rhs);

	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	public:
		iterator();
		iterator(const iterator &src);
		~iterator();

		void			setData(T *src);
		T				operator*(void);
		iterator		&begin();
		iterator		&end();
		iterator		&operator=(const iterator &rhs);
		bool			operator!=(const iterator &rhs);
		iterator		operator++(int);
		iterator		&operator++(void);
		iterator		operator--(int);
		iterator		&operator--(void);

	private:
		T					*_data;

	};
	iterator			begin();
	iterator			end();

};

/******************************************************************************/
/***************************** MUTANT STACK ***********************************/
/******************************************************************************/

template <typename T> 
MutantStack<T>::MutantStack() {}

template <typename T> 
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {*this = src;}

template <typename T> 
MutantStack<T>::~MutantStack() {}

template <typename T> 
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {std::stack<T>::operator=(rhs); return *this;}

/******************************************************************************/
/******************************** ITERATOR ************************************/
/******************************************************************************/

template <typename T>
MutantStack<T>::iterator::iterator() {}

template <typename T>
MutantStack<T>::iterator::iterator(typename MutantStack<T>::iterator const &src)
{
	iterator::operator=(src);
}

template <typename T>
MutantStack<T>::iterator::~iterator() {}

template <typename T> 
void			MutantStack<T>::iterator::setData(T *src){this->_data = src;}

template <typename T> 
T				MutantStack<T>::iterator::operator*(void) {return (*this->_data);}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin()
{
	typename MutantStack<T>::iterator	it;

	it.setData((&this->top()) - this->size() + 1);
	return (it);
}

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end()
{
	typename MutantStack<T>::iterator	it;

	it.setData(&this->top() + 1);
	return (it);
}

template<typename T>
typename MutantStack<T>::iterator		&MutantStack<T>::iterator::operator=(typename MutantStack<T>::iterator const &rhs)
{
	std::iterator<std::random_access_iterator_tag, T>::operator=(rhs);
	this->_data = rhs._data;
	return (*this);
}

template<typename T>
bool						MutantStack<T>::iterator::operator!=(typename MutantStack<T>::iterator const &rhs){return (this->_data != rhs._data);}

template<typename T>
typename MutantStack<T>::iterator		&MutantStack<T>::iterator::operator++(void)
{
	++(this->_data);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator++(int)
{
	MutantStack<T>::iterator tmp = *this;

	++(this->_data);
	return (tmp);
}

template<typename T>
typename MutantStack<T>::iterator		&MutantStack<T>::iterator::operator--(void)
{
	--(this->_data);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator		MutantStack<T>::iterator::operator--(int)
{
	MutantStack<T>::iterator tmp = *this;

	--(this->_data);
	return (tmp);
}

#endif
