// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sheep.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 09:07:43 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 10:59:22 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHEEP_CLASS_HPP
# define SHEEP_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternDefault.class.hpp>
# include <AMovPatternSheep.class.hpp>
# include <AShootPatternDefault.class.hpp>

# include <iostream>
# include <ctime>

class Sheep : public AObject, public AMovPatternSheep
{
public:
	Sheep();
	Sheep(Sheep const &src);
	virtual ~Sheep();

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
	Sheep						&operator=(Sheep const &rhs);

	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
	static clock_t const		_moveCD;
	static int const			_moveChancesFactor;
};
//std::ostream					&operator<<(std::ostream &o, Sheep const &rhs);

#endif // *************************************************** SHEEP_CLASS_HPP //
