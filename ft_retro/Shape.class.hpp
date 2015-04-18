// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shape.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 15:34:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHAPE_CLASS_HPP
# define SHAPE_CLASS_HPP

# include <ft_retro.hpp>
# include <Game.class.hpp>

// # include <string>
# include <iostream>
//# include <stdexcept>

class Shape
{
public:
	virtual ~Shape();

	bool						putShape(Game const &g, int x, int y) const;
	bool						shapeFits(Game const &g, int x, int y) const;
	
	Shape(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
		  char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
		  char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]);
	Shape(Shape const &src);
	std::string					shapeToString(void) const;
	int							getTopSize(void) const;
	int							getBottomSize(void) const;
	int							getLeftSize(void) const;
	int							getRightSize(void) const;
	int							getMinYStr(void) const; //delete those getters
	int							getMaxYStr(void) const;
	int							getMinXStr(void) const;
	int							getMaxXStr(void) const;

	bool						doesCollide(Shape const &foe, int minMaxes[8]) const;
	
protected:	
	char const					**getFgChars(void) const;
	char const					**getFgColors(void) const;
	char const					**getBgColors(void) const;
	
private:
	Shape();
	Shape						&operator=(Shape const &rhs);
	char						_fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	char						_fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	char						_bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	int							_topSize;
	int							_bottomSize;
	int							_leftSize;
	int							_rightSize;
	int							_minYStr;
	int							_maxYStr;
	int							_minXStr;
	int							_maxXStr;
};
std::ostream					&operator<<(std::ostream &o, Shape const &rhs);

#endif // *************************************************** SHAPE_CLASS_HPP //
