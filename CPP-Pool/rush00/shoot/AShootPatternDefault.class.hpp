// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AShootPatternDefault.class.hpp                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 11:13:22 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 10:48:58 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASHOOTPATTERNDEFAULT_CLASS_HPP
# define ASHOOTPATTERNDEFAULT_CLASS_HPP

# include <ft_retro.hpp>
# include <IShootIA.class.hpp>
//# include <iostream>
# include <ctime>
//# include <stdexcept>

class AShootPatternDefault : public IShootIA
{
public:
	AShootPatternDefault(int num, clock_t shootCD, int shootChancesFactor,
		clock_t missileMovCD);
	virtual ~AShootPatternDefault();

	int							tryShoot(Game &g);

protected:
private:
	AShootPatternDefault(AShootPatternDefault const &src);
	AShootPatternDefault		&operator=(AShootPatternDefault const &rhs);
	AShootPatternDefault();

	int const					_num;
	clock_t const				_shootCD;
	int const					_shootChancesFactor;
	clock_t						_lastShootTime;
	clock_t const				_missileMovCD;
};
//std::ostream					&operator<<(std::ostream &o, AShootPatternDefault const &rhs);

#endif // ************************************ ASHOOTPATTERNDEFAULT_CLASS_HPP //
