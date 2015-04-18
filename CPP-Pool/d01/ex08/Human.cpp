// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/01 10:15:48 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/01 10:46:18 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human()
{
}

Human::~Human(){}

void	Human::meleeAttack(const std::string &target)
{
	std::cout << "Human attack " << target << " (melee attack)." << std::endl;
}

void	Human::rangedAttack(const std::string &target)
{
	std::cout << "Human attack " << target << " (ranged attack)." << std::endl;
}

void	Human::intimidatingShout(const std::string &target)
{
	std::cout << "Human attack " << target << " (intimidate shout)." << std::endl;
}

void	Human::action(const std::string &action_name, const std::string &target)
{
	void Human::ft_ptr[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	int	i = -1;
	while (++i < 3)
	{
		if (names[i] == action_name)
			this->*HumanMemFn[i](target);
	}
}

