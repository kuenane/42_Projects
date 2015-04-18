// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/01 10:12:37 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/01 18:42:56 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class Human
{

private:
	void		meleeAttack(const std::string &target);
	void		rangedAttack(const std::string &target);
	void		intimidatingShout(const std::string &target);

	

public:
	Human();
	~Human();
	void		action(const std::string &action_name, const std::string &target);

};

#endif


