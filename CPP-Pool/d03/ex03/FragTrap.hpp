// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 15:16:46 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/10 13:22:16 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(const std::string &name);
	FragTrap(FragTrap const &src);
	virtual ~FragTrap(void);
	FragTrap &operator=(FragTrap const &rhs);

	void	vaulthunter_dot_exe(std::string const &target);
	void	plugAttack(std::string const &target) const;
	void	thorAttack(std::string const &target) const;
	void	zazAttack(std::string const &target) const;
	void	NSAttack(std::string const &target) const;
	void	stCardAttack(std::string const &target) const;
	
private:
	FragTrap();

};

#endif
