/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:23:19 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 17:51:04 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie destroyed" << std::endl;
}

void	Zombie::SetName(std::string name)
{
	_Name = name;
}
void	Zombie::Announce(void)
{
	std::cout << _Name << ": BRAIIIIINZZZzz...\n";
}