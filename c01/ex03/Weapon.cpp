/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:01:12 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/11 15:36:14 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
	_Type = type;
}

Weapon::~Weapon(void){
	
}


const std::string& Weapon::getType(void){
	return _Type;
}

void	Weapon::setType(std::string type){
	_Type = type;
}