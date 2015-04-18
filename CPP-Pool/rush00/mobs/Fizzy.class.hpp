// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fizzy.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:37 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/19 11:03:38 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIZZY_CLASS_HPP
# define FIZZY_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternDefault.class.hpp>
# include <AMovPatternSheep.class.hpp>

# include <iostream>
# include <ctime>

class Fizzy : public AObject, public AMovPatternSheep
{
public:
	Fizzy();
	Fizzy(Fizzy const &src);
	virtual ~Fizzy();

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
	Fizzy						&operator=(Fizzy const &rhs);

	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
	static clock_t const		_moveCD;
	static int const			_moveChancesFactor;
};
//std::ostream					&operator<<(std::ostream &o, Fizzy const &rhs);

#endif // *************************************************** FIZZY_CLASS_HPP //
