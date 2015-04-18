// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:14:12 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 15:14:13 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{

public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &src);
	virtual ~AssaultTerminator();

	virtual ISpaceMarine	*clone(void) const;
	virtual void			battleCry(void) const;
	virtual void			rangedAttack(void) const;
	virtual void			meleeAttack(void) const;
	AssaultTerminator			&operator=(const AssaultTerminator &rhs);

};

#endif
