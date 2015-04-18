// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//    PresidentialPardonForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 19:44:03 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:32:51 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:
	 PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();

	virtual void	execute(Bureaucrat const &executor) const;
	
protected:

private:
	 PresidentialPardonForm();
	 PresidentialPardonForm		&operator=(PresidentialPardonForm const &rhs);
	 PresidentialPardonForm(PresidentialPardonForm const &src);
};

#endif
