/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:29:19 by tknibbe           #+#    #+#             */
/*   Updated: 2024/07/01 15:55:05 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#include <string>
#include <iostream>

// typedef void (Harl::*func)(void);

void	Harl::complain(std::string level)
{
	std::string	options[] = {"debug", "info", "warning", "error"};
	int i;
	for(i = 0; i < 4; i++)
	{
		if (options[i] == level)
			break;
	}
	if (i == 4)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else
	{
		switch (i)
		{
			case 0:
				Harl::debug();
			case 1:
				Harl::info();
			case 2:
				Harl::warning();
			case 3:
				Harl::error();
		}
	}
}

void	Harl::debug(void){
	std::cout << "\n[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}
void	Harl::info(void){
	std::cout << "\n[INFO]\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!\n";
}
void	Harl::warning(void){
	std::cout << "\n[WARNING]\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month.\n";
}
void	Harl::error(void){
	std::cout <<  "\n[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}
