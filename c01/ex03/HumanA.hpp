/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:06:29 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 16:18:53 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

#pragma once

class HumanA{
	private:
		Weapon		&_Weapon;
		std::string	_Name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
};