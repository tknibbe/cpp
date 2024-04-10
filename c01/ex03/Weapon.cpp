/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:01:12 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 16:47:40 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	_Type = type;
}

Weapon::~Weapon(){
	
}


const std::string& Weapon::getType(void){
	return _Type;
}

void	Weapon::setType(std::string type){
	_Type = type;
}