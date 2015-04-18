// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 16:12:12 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/23 17:36:11 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
public:

	Enemy(int hp, const std::string &type);
	Enemy(Enemy const &src);
	virtual ~Enemy();
	Enemy						&operator=(Enemy const &rhs);

	const std::string			&getType(void) const;
	int							getHp(void) const;
	virtual void				takeDamage(int);

	
protected:
	int				_hp;
	std::string		_type;

	
private:
	Enemy();

};

#endif
