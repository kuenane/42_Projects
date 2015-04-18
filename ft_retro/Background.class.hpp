// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Background.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 14:13:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 15:17:37 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BACKGROUND_CLASS_HPP
# define BACKGROUND_CLASS_HPP

# include <ft_retro.hpp>
# include <Game.class.hpp>
# include <iostream>
//# include <stdexcept>

class Background
{
public:
	Background(int x, int y, Game &g);
	virtual ~Background();

	void						putBackground(void);
	
protected:
private:
	Background();
	Background(Background const &src);
	Background					&operator=(Background const &rhs);
	int							_phase;
	int							_x;
	int							_y;
	Game						&_g;
	std::string const			*_lines;
	char const					*_linesFgColors;
	char const					*_linesBgColors;

	std::string					*_dstFgChars;
	char						*_dstFgColors;
	char						*_dstBgColors;
};
//std::ostream					&operator<<(std::ostream &o, Background const &rhs);

#endif // ********************************************** BACKGROUND_CLASS_HPP //
