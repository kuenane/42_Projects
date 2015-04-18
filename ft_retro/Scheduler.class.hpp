// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scheduler.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 10:41:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 07:33:34 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCHEDULER_CLASS_HPP
# define SCHEDULER_CLASS_HPP

# include <ctime>
# include <Game.class.hpp>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class Scheduler
{
public:
	Scheduler(clock_t waitTime, clock_t waveCD);
	virtual ~Scheduler();	
	void						tryNewWave(Game &g);
	
protected:
private:
	Scheduler();
	Scheduler(Scheduler const &src);
	Scheduler					&operator=(Scheduler const &rhs);
	clock_t						_lastWave;
	clock_t						_waveCD;
	int							_waveCount;
};
//std::ostream					&operator<<(std::ostream &o, Scheduler const &rhs);

#endif // *********************************************** SCHEDULER_CLASS_HPP //
