// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/28 10:34:39 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/30 10:55:38 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException):
_name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructed" << std::endl;
}

Bureaucrat::~Bureaucrat(){std::cout << "Bureaucrat destructed" << std::endl;}

const std::string			&Bureaucrat::getName(void) const{return this->_name;}
int							Bureaucrat::getGrade(void) const{return this->_grade;}

void						Bureaucrat::incGrade() throw(GradeTooHighException)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade -= 1;
	std::cout << "Grade incremented, new grade: " << this->_grade << std::endl;
}

void						Bureaucrat::decGrade() throw(GradeTooLowException)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade += 1;
	std::cout << "Grade decremented, new grade: " << this->_grade << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw():
std::exception() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &rhs) throw():
std::exception()
{(void)rhs;}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw():
std::exception(){}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &rhs) throw():
std::exception()
{(void)rhs;}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}
