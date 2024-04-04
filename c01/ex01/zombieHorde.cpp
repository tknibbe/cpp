/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:30:30 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 17:50:34 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zomb = new Zombie[N];
	if (!zomb)
		exit(EXIT_FAILURE);
	for (int i = 0;i < N;i++)
	{
		std::cout << "zombie #" << i << " is assigned their name" << std::endl;
		zomb[i].SetName(name);
	}
	return zomb;
}