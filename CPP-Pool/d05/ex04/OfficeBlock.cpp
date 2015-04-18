// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:18:01 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 16:08:34 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() :
_intern(NULL), _signer(NULL), _executor(NULL)
{
	std::cout << "Default OfficeBlock constructed" << std::endl;
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) :
_intern(intern), _signer(signer), _executor(executor)
{
	std::cout << "OfficeBlock constructed" << std::endl;
}

OfficeBlock::~OfficeBlock(){std::cout << "OfficeBlock destructed" << std::endl;}

Intern const		*OfficeBlock::getIntern(void) const{return this->_intern;}
Bureaucrat const	*OfficeBlock::getSigner(void) const{return this->_signer;}
Bureaucrat const	*OfficeBlock::getExecutor(void) const{return this->_executor;}

void				OfficeBlock::setIntern(Intern *c){this->_intern=c;}
void				OfficeBlock::setSigner(Bureaucrat *c){this->_signer=c;}
void				OfficeBlock::setExecutor(Bureaucrat *c){this->_executor=c;}

OfficeBlock::MissingAnAttribute::MissingAnAttribute() throw(): std::exception(){}

OfficeBlock::MissingAnAttribute::MissingAnAttribute(MissingAnAttribute const &rhs) throw():
std::exception()
{(void)rhs;}

OfficeBlock::MissingAnAttribute::~MissingAnAttribute() throw(){}

const char *OfficeBlock::MissingAnAttribute::what() const throw()
{
	return ("At least one attribute is unset.");
}

void			OfficeBlock::doBureaucracy(const std::string &form, const std::string &target)
{
	if (!this->_intern || !this->_signer || !this->_executor)
		throw MissingAnAttribute();
	Form	*toto = this->_intern->makeForm(form, target);
	this->_signer->signForm(*toto);
	this->_executor->executeForm(*toto);
}

