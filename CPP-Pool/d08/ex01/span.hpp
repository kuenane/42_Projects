// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 20:03:23 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/13 20:03:24 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <vector>
# include <cstdlib>
# include <algorithm>

class Span
{

public:
	Span(unsigned int n);
	virtual ~Span();

	virtual void			addNumber(int nb) throw(std::exception);
	virtual void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) throw(std::exception);
	virtual unsigned int	shortestSpan(void) const throw(std::exception);
	virtual unsigned int	longestSpan(void) const throw(std::exception);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
private:
	Span();
	Span(Span const &src);
	Span	&operator=(Span const &rhs);
	virtual unsigned int	_giveSpan(int a, int b) const;

	unsigned int		_n;
	std::vector<int> 	_vec;

};

#endif
