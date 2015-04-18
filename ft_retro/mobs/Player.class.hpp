// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:09:21 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 14:45:29 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>
# include <Game.class.hpp>
// # include <AShootPatternDefault.class.hpp>

# include <iostream>
# include <ctime>

class Player : public AObject
{
public:
	Player(Game &g);
	virtual ~Player();

	std::string const			&getName() const;
	Shape const					&getShape() const;
	bool						getDoesMove() const;
	bool						getDoesShoot() const;

	void						moveCall(Game const &g);
	void						moveEvent(Game const &g, int x, int y);
	
	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	void                        setDeleteObject(bool b);
	Game						&getGame(void);
	
protected:
private:
	Player						&operator=(Player const &rhs);
	Player();
	Player(Player const &src);
	
	Game						&_game;
	static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
};
//std::ostream					&operator<<(std::ostream &o, Player const &rhs);

#endif // *************************************************** PLAYER_CLASS_HPP //
