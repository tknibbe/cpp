/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:21:16 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 17:48:38 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie *zomb;
	zomb = zombieHorde(N, "tom");

	for (int i = 0; i < N;i++)
		zomb[i].Announce();

	delete [] zomb;
	return (EXIT_SUCCESS);
}