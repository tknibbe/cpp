/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:29:19 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 21:05:05 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#include <string>
#include <iostream>

typedef void (Harl::*func)(void);

void	Harl::complain(std::string level)
{
	func	functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	options[] = {"debug", "info", "warning", "error"};
	int i;
	for(i = 0; i < 4; i++)
	{
		if (options[i] == level)
		{
			(this->*(functions[i]))();
			return;
		}
	}
	std::cout << "This does not appear to be a level Harl supports\n";
}

void	Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}
void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!\n";
}
void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month.\n";
}
void	Harl::error(void){
	std::cout <<  "This is unacceptable! I want to speak to the manager now.\n";
}
