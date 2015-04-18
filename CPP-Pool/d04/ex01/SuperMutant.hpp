// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 16:43:47 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 08:56:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	
public:

	SuperMutant();
	SuperMutant(SuperMutant const &src);
	virtual ~SuperMutant();
	SuperMutant					&operator=(SuperMutant const &rhs);
	virtual void takeDamage(int dmg);
	
protected:

private:

};

#endif
