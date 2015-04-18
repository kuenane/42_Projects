// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternLombric.class.hpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 15:13:26 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/19 15:13:27 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVPATTERNLOMBRIC_CLASS_HPP
# define AMOVPATTERNLOMBRIC_CLASS_HPP

# include <ft_retro.hpp>
# include <IMovIA.class.hpp>
# include <ctime>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class AMovPatternLombric : public IMovIA
{
public:
	AMovPatternLombric(clock_t moveCD, int strafeChancesFactor);
	virtual ~AMovPatternLombric();

	// AMovPatternLombric();
	int							tryMove(Game const &g);
	
protected:
private:
	AMovPatternLombric();
	AMovPatternLombric(AMovPatternLombric const &src);
	AMovPatternLombric			&operator=(AMovPatternLombric const &rhs);

	clock_t						_lastMoveTime;
	clock_t const				_moveCD;
	int const					_strafeChancesFactor;
	char						_direction;
	void						move(Game const &g, Shape const &s,
									 int x, int y);
};
//std::ostream					&operator<<(std::ostream &o, AMovPatternLombric const &rhs);

#endif // **************************************** AMOVPATTERNLOMBRIC_CLASS_HPP //
