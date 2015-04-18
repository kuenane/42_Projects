// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhBook.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 19:03:46 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/12 09:48:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PHBOOK_CLASS_HPP
# define PHBOOK_CLASS_HPP

# include <string>

class PhBook {

public:
	PhBook(void);
	~PhBook(void);
	void fill_fields(void);
	void print_title_general(void) const;
	void print_general(int index) const;
	void print_detailed(void) const;
	std::string give_field(const char *msg) const;

private:
	std::string		_fields[11];
	std::string		_fmt_str(std::string toformat) const;
	
};

#endif
