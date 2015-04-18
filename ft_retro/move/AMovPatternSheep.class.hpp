// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternSheep.class.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 07:35:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 08:45:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVPATTERNSHEEP_CLASS_HPP
# define AMOVPATTERNSHEEP_CLASS_HPP

# include <ft_retro.hpp>
# include <IMovIA.class.hpp>
# include <ctime>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class AMovPatternSheep : public IMovIA
{
public:
	AMovPatternSheep(clock_t moveCD, int strafeChancesFactor);
	virtual ~AMovPatternSheep();

	// AMovPatternSheep();
	int							tryMove(Game const &g);
	
protected:
private:
	AMovPatternSheep();
	AMovPatternSheep(AMovPatternSheep const &src);
	AMovPatternSheep			&operator=(AMovPatternSheep const &rhs);

	clock_t						_lastMoveTime;
	clock_t const				_moveCD;
	int const					_strafeChancesFactor;
	void						move(Game const &g, Shape const &s,
									 int x, int y);
};
//std::ostream					&operator<<(std::ostream &o, AMovPatternSheep const &rhs);

#endif // **************************************** AMOVPATTERNSHEEP_CLASS_HPP //
