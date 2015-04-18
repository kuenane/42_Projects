// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Centipede.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:02:15 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/12 18:10:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CENTIPEDE_CLASS_HPP
# define CENTIPEDE_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternDefault.class.hpp>
# include <AMovPatternSheep.class.hpp>
# include <AShootPatternDefault.class.hpp>

# include <iostream>
# include <ctime>

class Centipede : public AObject, public AMovPatternSheep, public AShootPatternDefault
{
public:
	Centipede();
	virtual ~Centipede();

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

	void						shootCall(Game &g);
protected:
private:
	Centipede(Centipede const &src);
	Centipede						&operator=(Centipede const &rhs);

	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
	static clock_t const		_moveCD;
	static int const			_moveChancesFactor;
};
//std::ostream					&operator<<(std::ostream &o, Centipede const &rhs);

#endif // *************************************************** CENTIPEDE_CLASS_HPP //
