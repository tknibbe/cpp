/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:32:36 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 16:06:12 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	//heap allocated class
	Zombie *Robert = newZombie("Rob");
	Robert->announce();
	delete Robert;

	//stack allocated class
	randomChump("bob");
	
	return EXIT_SUCCESS;
}