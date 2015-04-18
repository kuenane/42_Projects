// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 11:12:00 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 11:32:37 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:

	Squad();
	Squad(const Squad &src);
	virtual ~Squad();
	Squad			&operator=(const Squad &rhs);

	virtual int 	getCount() const;
	ISpaceMarine	*getUnit(int n);
	ISpaceMarine	*getUnit(int n) const;
	virtual int 	push(ISpaceMarine *marine);

private:
	int				_count;
	ISpaceMarine	**_units;

	void			_kill_units(void);

};

#endif
