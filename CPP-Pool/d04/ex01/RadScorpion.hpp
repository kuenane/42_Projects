// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/23 16:43:47 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/24 08:56:07 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	
public:

	RadScorpion();
	RadScorpion(RadScorpion const &src);
	virtual ~RadScorpion();
	RadScorpion					&operator=(RadScorpion const &rhs);
	
protected:

private:

};

#endif
