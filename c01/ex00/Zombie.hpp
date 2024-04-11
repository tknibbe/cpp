/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:50 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/11 13:15:33 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

#pragma once

class Zombie
{
	private:
		std::string _Name;
	
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie	*newZombie (std::string name);
void	randomChump(std::string name);


#endif