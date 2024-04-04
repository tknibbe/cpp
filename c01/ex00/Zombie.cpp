/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:21:23 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 15:49:22 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void)
{
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (std::string name){
	_Name = name;
}

Zombie::~Zombie(void){
	std::cout << _Name << " has been destroyed" << std::endl;
}