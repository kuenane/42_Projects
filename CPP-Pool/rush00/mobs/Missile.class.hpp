// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:37 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 12:09:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MISSILE_CLASS_HPP
# define MISSILE_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternMissile.class.hpp>

# include <iostream>
# include <ctime>

class Missile : public AObject, public AMovPatternMissile
{
public:
	Missile(float angle, int srcX, int srcY, int movCD);
	Missile(Missile const &src);
	virtual ~Missile();

	std::string const			&getName() const;
	Shape const					&getShape() const;
	bool						getDoesMove() const;
	bool						getDoesShoot() const;
	float						getAngle(void) const;
	int							getSrcX(void) const;
	int							getSrcY(void) const;
	int							getMovCD(void) const;
	// AObject						*getThis(void);

	void						moveCall(Game const &g);

	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	void						setDeleteObject(bool b);

protected:
private:
	Missile						&operator=(Missile const &rhs);
	Missile();

	float						_angle;
	int							_srcX;
	int							_srcY;
	int							_movCD;
	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static Shape const		  _mobShapePlayer;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
};
//std::ostream					&operator<<(std::ostream &o, Missile const &rhs);

#endif // *************************************************** MISSILE_CLASS_HPP //
