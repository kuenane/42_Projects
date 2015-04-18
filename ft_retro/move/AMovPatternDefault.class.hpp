// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternDefault.class.hpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 10:44:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 07:39:06 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVPATTERNDEFAULT_CLASS_HPP
# define AMOVPATTERNDEFAULT_CLASS_HPP

# include <ft_retro.hpp>
# include <IMovIA.class.hpp>
# include <ctime>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class AMovPatternDefault : public IMovIA
{
public:
	AMovPatternDefault(clock_t moveCD, int moveChancesFactor);
	virtual ~AMovPatternDefault();
	
	int							tryMove(Game const &g);
protected:
private:
	AMovPatternDefault(AMovPatternDefault const &src);
	AMovPatternDefault			&operator=(AMovPatternDefault const &rhs);
	AMovPatternDefault();

	void						move(Game const &g, Shape const &s,
									int x, int y);
	clock_t						_lastMoveTime;
	clock_t const				_moveCD;
	int const					_moveChancesFactor;
};
//std::ostream					&operator<<(std::ostream &o, AMovPatternDefault const &rhs);

#endif // ************************************** AMOVPATTERNDEFAULT_CLASS_HPP //
