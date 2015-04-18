// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 19:44:03 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:34:07 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	
	virtual void	execute(Bureaucrat const &executor) const;
	
protected:

private:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm		&operator=(ShrubberyCreationForm const &rhs);
};

#endif
