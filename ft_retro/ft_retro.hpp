// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 14:53:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

class Game;
class Background;
class Scheduler;

class AObject;
class Shape;

class IMovIA;
class AMovPatternDefault;
class AMovPatternSheep;
class AMovPatternLombric;

class IShootIA;
class AShootPatternDefault;

class Snake;
class Pig;
class Sheep;
class Centipede;
class Lombric;
class Missile;
class Player;

# include <objects_shapes.hpp>

# define DELTA_REFRESH_SCREEN 40000
# define DELTA_REFRESH_EVENTS DELTA_REFRESH_SCREEN

# define MIN(A, B) ((A) <= (B) ? (A) : (B))
# define MAX(A, B) ((A) >= (B) ? (A) : (B))

#endif // ****************************************************** FT_RETRO_HPP //
