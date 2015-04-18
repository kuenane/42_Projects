// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:09:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 15:53:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <ft_retro.hpp>
# include <AObject.class.hpp>

# include <iostream>
# include <vector>
//# include <stdexcept>

class Game
{
public:
	Game(int maxX, int maxY);
	virtual ~Game();
	int							getMaxX(void) const;
	int							getMaxY(void) const;

	std::string					*getDstFgChars(void) const;
	char						*getDstFgColors(void) const;
	char						*getDstBgColors(void) const;
	void						putImage(void) const;
	void						putObjects(void) const;

	void						setFgChar(int x, int y, char c) const;
	void						setFgColor(int x, int y, char c) const;

	void						keyboard_input(void);
	void						leave_game(std::string msg);
	
	void						popSheep(int count);
	void						popPig(int count);
	void						popLombric(int count);
	void						popSnake(int count);
	void						popCentipede(int count);
	void						popFizzy(int count);
	void						popMissile(AObject const *shooter, float angle,
										   clock_t movCD);
	void						popMissileFriendly(AObject const *shooter, float angle,
										   clock_t movCD);

	std::vector<AObject*>		_objsVector;
	std::vector<AObject*>		_objsVectorFriendly;
protected:
private:
	Game();
	Game(Game const &src);
	Game						&operator=(Game const &rhs);
	int const					_maxX;
	int const					_maxY;
	std::string					*_dstFgChars;
	char						*_dstFgColors;
	char						*_dstBgColors;
};
//std::ostream					&operator<<(std::ostream &o, Game const &rhs);

#endif // **************************************************** GAME_CLASS_HPP //
