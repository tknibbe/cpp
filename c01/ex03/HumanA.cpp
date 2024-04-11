/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:06:20 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/11 15:36:24 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _Weapon(weapon){
	_Name = name;
}

HumanA::~HumanA(void){
	
}

void HumanA::attack(void)
{
	std::cout << _Name << " attacks with their " << _Weapon.getType() << std::endl;
}