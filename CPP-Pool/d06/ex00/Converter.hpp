// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 21:45:38 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/14 21:45:44 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <cfloat>
# include <sstream>
# include <iomanip>

class Converter
{

public:
	Converter(const std::string &input);
	virtual ~Converter();

	bool				detect_type(void);
	void				print(void);

private:
	Converter();
	Converter(Converter const &src);
	Converter			&operator=(Converter const &rhs);

	void				_search_char(void);
	void				_search_int(void);
	void				_search_double(void);
	void				_search_float(void);

	void				_print_char(void);
	void				_print_int(void);
	void				_print_double(void);
	void				_print_float(void);

	std::string			_input;
	char				_type;
};

#endif
