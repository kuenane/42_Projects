// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:14:12 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/11 15:14:13 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:
	TacticalMarine();
	TacticalMarine(const TacticalMarine &src);
	virtual ~TacticalMarine();

	virtual ISpaceMarine	*clone(void) const;
	virtual void			battleCry(void) const;
	virtual void			rangedAttack(void) const;
	virtual void			meleeAttack(void) const;
	TacticalMarine			&operator=(const TacticalMarine &rhs);

};

#endif
