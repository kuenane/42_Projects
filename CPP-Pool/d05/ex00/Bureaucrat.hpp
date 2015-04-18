// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:32 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/30 10:57:25 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
public:
	
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src) throw();
		virtual ~GradeTooHighException() throw();
		virtual const char	*what() const throw();
	private:
		GradeTooHighException &operator=(GradeTooHighException const &rhs);
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src) throw();
		virtual ~GradeTooLowException() throw();
		virtual const char	*what() const throw();
	private:
		GradeTooLowException &operator=(GradeTooLowException const &rhs);
	};
	
	Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);
	virtual ~Bureaucrat();

	const std::string			&getName(void) const;
	int							getGrade(void) const;

	void						incGrade() throw(GradeTooHighException);
	void						decGrade() throw(GradeTooLowException);
	
protected:

private:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat	&operator=(Bureaucrat const &rhs);

	const std::string	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
