// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 14:17:57 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/31 16:11:40 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>
# include <stdexcept>
# include "Intern.hpp"

class OfficeBlock
{

public:
	OfficeBlock();
	OfficeBlock(Intern *_intern, Bureaucrat *signer, Bureaucrat *executor);
	virtual ~OfficeBlock();

	Intern const		*getIntern(void) const;
	Bureaucrat const	*getSigner(void) const;
	Bureaucrat const	*getExecutor(void) const;

	void				setIntern(Intern *c);
	void				setSigner(Bureaucrat *c);
	void				setExecutor(Bureaucrat *c);
	
	void				doBureaucracy(const std::string &form, const std::string &target);
	
	class MissingAnAttribute : public std::exception
	{
	public:
		MissingAnAttribute() throw();
		MissingAnAttribute(MissingAnAttribute const &src) throw();
		virtual ~MissingAnAttribute() throw();
		virtual const char*what() const throw();
	private:
		MissingAnAttribute &operator=(MissingAnAttribute const &rhs);
	};
	
protected:
	
private:
	Intern		*_intern;
	Bureaucrat	*_signer;
	Bureaucrat	*_executor;
	
	OfficeBlock(OfficeBlock const *src);
	OfficeBlock		*operator=(OfficeBlock const *rhs);

};

#endif
