// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 09:55:41 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 09:36:44 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"

Form::Form(const std::string &name, int grade_sign, int grade_exec, const std::string &target) throw(GradeTooHighException, GradeTooLowException) :
_name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec), _target(target)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
	std::cout << "Form created" << std::endl;
}

Form::~Form(){std::cout << "Form destructed" << std::endl;}

std::ostream		&operator<<(std::ostream &o, Form const &rhs)
{
	if (rhs.getSigned() == true)
		std::cout << "The form is signed." << std::endl;
	else
		std::cout << "The form is unsigned." << std::endl;
	return (o);
}

const std::string	&Form::getName(void) const{return this->_name;}
bool				Form::getSigned(void) const{return this->_signed;}
int					Form::getGrade_sign(void) const{return this->_grade_sign;}
int					Form::getGrade_exec(void) const{return this->_grade_exec;}
const std::string	&Form::getTarget(void) const{return this->_target;}

Form::GradeTooHighException::GradeTooHighException() throw(): std::exception() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &rhs) throw():
std::exception()
{(void)rhs;}

Form::GradeTooHighException::~GradeTooHighException() throw(){}

const char *Form::GradeTooHighException::what() const throw(){return ("Too high");}

Form::GradeTooLowException::GradeTooLowException() throw(): std::exception(){}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &rhs) throw() : std::exception()
{(void)rhs;}

Form::GradeTooLowException::~GradeTooLowException() throw(){}

const char *Form::GradeTooLowException::what() const throw(){return ("Too low");}

Form::FormAlreadySigned::FormAlreadySigned() throw(): std::exception(){}

Form::FormAlreadySigned::FormAlreadySigned(FormAlreadySigned const &rhs) throw() : std::exception()
{(void)rhs;}

Form::FormAlreadySigned::~FormAlreadySigned() throw(){}

const char *Form::FormAlreadySigned::what() const throw(){return ("Already signed");}

Form::FormNotSigned::FormNotSigned() throw(): std::exception(){}

Form::FormNotSigned::FormNotSigned(FormNotSigned const &rhs) throw() : std::exception()
{(void)rhs;}

Form::FormNotSigned::~FormNotSigned() throw(){}

const char *Form::FormNotSigned::what() const throw(){return ("Not signed");}

void Form::beSigned(const Bureaucrat &src) throw(GradeTooLowException, FormAlreadySigned)
{
	if (this->_signed == true)
		throw(FormAlreadySigned());
	else if (src.getGrade() > this->_grade_sign)
		throw(GradeTooLowException());
	else
		this->_signed = true;
}

void	Form::try_execute(const Bureaucrat &executor) const throw (GradeTooLowException, FormNotSigned)
{
	if (this->_signed == false)
		throw(FormNotSigned());
	else if (executor.getGrade() > this->_grade_exec)
		throw(GradeTooLowException());
	else
		this->execute(executor);
}
