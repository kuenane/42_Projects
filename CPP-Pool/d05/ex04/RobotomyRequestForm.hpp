// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 19:44:03 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:33:07 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	
	virtual void	execute(Bureaucrat const &executor) const;
	
protected:

private:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm		&operator=(RobotomyRequestForm const &rhs);
};

#endif
