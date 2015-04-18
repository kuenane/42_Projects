// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:58:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/12 18:11:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PIG_CLASS_HPP
# define PIG_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
# include <AMovPatternDefault.class.hpp>
# include <AMovPatternSheep.class.hpp>
# include <AShootPatternDefault.class.hpp>

# include <iostream>
# include <ctime>
//# include <stdexcept>

class Pig : public AObject, public AMovPatternDefault, public AShootPatternDefault
{
public:
	Pig();
	virtual ~Pig();

	std::string const			&getName() const;
	Shape const					&getShape() const;
	bool						getDoesMove() const;
	bool						getDoesShoot() const;

	void						moveCall(Game const &g);
	void						shootCall(Game &g);
	
	
	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	void						setDeleteObject(bool b);
	
protected:
private:
	Pig							&operator=(Pig const &rhs);
	Pig(Pig const &src);
	
	static std::string const	_mobName;
	static Shape const			_mobShape;
	static bool const			_doesMove;
	static bool const			_doesShoot;
	static clock_t const		_moveCD;
	static int const			_moveChancesFactor;
	
};
//std::ostream					&operator<<(std::ostream &o, Pig const &rhs);

#endif // ***************************************************** PIG_CLASS_HPP //
