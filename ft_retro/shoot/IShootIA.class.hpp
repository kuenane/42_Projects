// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IShootIA.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 11:09:52 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 10:49:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISHOOTIA_CLASS_HPP
# define ISHOOTIA_CLASS_HPP

# include <ft_retro.hpp>
# include <Game.class.hpp>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class IShootIA
{
public:
	IShootIA();
	virtual ~IShootIA();

	virtual int					tryShoot(Game &g) = 0;
	// IShootIA();

protected:
private:
	IShootIA(IShootIA const &src);
	IShootIA					&operator=(IShootIA const &rhs);

};
//std::ostream					&operator<<(std::ostream &o, IShootIA const &rhs);

#endif // ************************************************ ISHOOTIA_CLASS_HPP //
