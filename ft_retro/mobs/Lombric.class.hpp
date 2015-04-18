// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lombric.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:24 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 18:11:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOMBRIC_CLASS_HPP
# define LOMBRIC_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternLombric.class.hpp>

# include <iostream>
# include <ctime>

class Lombric : public AObject, public AMovPatternLombric
{
public:
	Lombric();
	virtual ~Lombric();

	std::string const			&getName() const;
	Shape const					&getShape() const;
	bool						getDoesMove() const;
	bool						getDoesShoot() const;

	void						moveCall(Game const &g);

	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	void                        setDeleteObject(bool b);

protected:
private:
	Lombric						&operator=(Lombric const &rhs);
	Lombric(Lombric const &src);
	
	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
	static clock_t const		_moveCD;
	static int const			_moveChancesFactor;
};
//std::ostream					&operator<<(std::ostream &o, Lombric const &rhs);

#endif // *************************************************** LOMBRIC_CLASS_HPP //
