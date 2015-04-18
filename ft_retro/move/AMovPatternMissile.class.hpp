// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternMissile.class.hpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:01:40 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 08:27:48 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVPATTERNMISSILE_CLASS_HPP
# define AMOVPATTERNMISSILE_CLASS_HPP

# include <ft_retro.hpp>
# include <IMovIA.class.hpp>
# include <ctime>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class AMovPatternMissile : public IMovIA
{
public:
	AMovPatternMissile(clock_t moveCD, float angle, int srcX, int srcY);
	virtual ~AMovPatternMissile();

	// AMovPatternMissile();
	int							tryMove(Game const &g);

protected:
private:
	AMovPatternMissile();
	AMovPatternMissile(AMovPatternMissile const &src);
	AMovPatternMissile			&operator=(AMovPatternMissile const &rhs);

	clock_t						_lastMoveTime;
	clock_t const				_moveCD;
	float const					_incX;
	float const					_incY;
	float						_coveredX;
	float						_coveredY;
	int const					_srcX;
	int const					_srcY;
	void						move(Game const &g, Shape const &s,
									 int x, int y);
};
//std::ostream					&operator<<(std::ostream &o, AMovPatternMissile const &rhs);

#endif // ************************************** AMOVPATTERNMISSILE_CLASS_HPP //
