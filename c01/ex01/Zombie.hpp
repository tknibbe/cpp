/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:24:20 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/04 17:42:29 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once

class Zombie
{
	private:
		std::string _Name;
	public:
		Zombie();
		~Zombie();
		void	Announce();
		void	SetName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );