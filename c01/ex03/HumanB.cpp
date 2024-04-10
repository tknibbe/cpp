/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:21:25 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 16:47:40 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name){
	_Name = name;
	_Weapon = nullptr;
}

HumanB::~HumanB(){

};

void	HumanB::setWeapon(Weapon &weapon){
	_Weapon = &weapon;
}

void	HumanB::attack(void){
	std::cout << _Name << " attacks with their ";
	if (!_Weapon)
		std::cout << "bare hands" << std::endl;
	else
		std::cout << _Weapon->getType() << std::endl;
		
}