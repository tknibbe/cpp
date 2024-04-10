/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:03:18 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 16:20:40 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once

class Weapon{
	private:
		std::string _Type;
	public:
		Weapon(std::string type);
		~Weapon();
		const	std::string &getType(void);
		void	setType(std::string type);
};