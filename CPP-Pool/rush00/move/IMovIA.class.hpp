// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMovIA.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 10:27:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 10:26:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMOVIA_CLASS_HPP
# define IMOVIA_CLASS_HPP

# include <ft_retro.hpp>
# include <Game.class.hpp>
# include <Shape.class.hpp>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class IMovIA
{
public:
	IMovIA();
	virtual ~IMovIA();

	virtual int					getPosX(void) const = 0;
	virtual int					getPosY(void) const = 0;
	virtual void				setPosX(int x) = 0;
	virtual void				setPosY(int y) = 0;
	virtual void				setPosXY(int x, int y) = 0;
	virtual int					tryMove(Game const &g) = 0;
	virtual Shape const			&getShape(void) const = 0;
	virtual void				setDeleteObject(bool b) = 0;
	
protected:
private:
	IMovIA(IMovIA const &src);
	IMovIA						&operator=(IMovIA const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, IMovIA const &rhs);

#endif // ************************************************** IMOVIA_CLASS_HPP //
