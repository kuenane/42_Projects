// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 09:55:39 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:35:55 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;
# include "Bureaucrat.hpp"

class Form
{

public:

    class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src) throw();
		virtual ~GradeTooHighException() throw();
		virtual const char  *what() const throw();
	private:
		GradeTooHighException &operator=(GradeTooHighException const &rhs);
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src) throw();
		virtual ~GradeTooLowException() throw();
		virtual const char  *what() const throw();
	private:
		GradeTooLowException &operator=(GradeTooLowException const &rhs);
	};

	class FormAlreadySigned : public std::exception
	{
	public:
		FormAlreadySigned() throw();
		FormAlreadySigned(FormAlreadySigned const &src) throw();
		virtual ~FormAlreadySigned() throw();
		virtual const char  *what() const throw();
	private:
		FormAlreadySigned &operator=(FormAlreadySigned const &rhs);
	};

	class FormNotSigned : public std::exception
	{
	public:
		FormNotSigned() throw();
		FormNotSigned(FormNotSigned const &src) throw();
		virtual ~FormNotSigned() throw();
		virtual const char  *what() const throw();
	private:
		FormNotSigned &operator=(FormNotSigned const &rhs);
	};

	Form(const std::string &name, int grade_sign, int grade_exec, const std::string &target) throw(GradeTooHighException, GradeTooLowException);
	virtual ~Form();

	const std::string	&getName(void) const;
	bool				getSigned(void) const;
	int					getGrade_sign(void) const;
	int					getGrade_exec(void) const;
	const std::string	&getTarget(void) const;

	void		beSigned(const Bureaucrat &src) throw(GradeTooLowException, FormAlreadySigned);
	void		try_execute(Bureaucrat const &executor) const throw (GradeTooLowException, FormNotSigned);
	virtual void	execute(Bureaucrat const &executor) const = 0;
	
protected:

private:
	Form						&operator=(Form const &rhs);
	Form();
	Form(Form const &src);
	
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_exec;
	const std::string	_target;
	
};

std::ostream					&operator<<(std::ostream &o, Form const &rhs);

#endif
