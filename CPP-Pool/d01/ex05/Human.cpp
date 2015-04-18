// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:41:23 by wide-aze          #+#    #+#             //
//   Updated: 2015/04/07 14:01:33 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human(void){std::cout << "Human constructed" << std::endl;}

Human::~Human(void){std::cout << "Human destructed" << std::endl;}

std::string	Human::identify(void) const{return (this->_Brain.identify());}

const Brain& Human::getBrain(void){return (this->_Brain);}
