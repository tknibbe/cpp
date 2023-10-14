/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:01 by tknibbe           #+#    #+#             */
/*   Updated: 2023/10/14 17:22:06 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
}

PhoneBook::~PhoneBook(void){
}

void PhoneBook::add_contact()
{
	static int	contact_count = 0;

	if (contact_count > 7)
		contact_count = 0;
	std::cout << "adding :)" << contact_count << std::endl;
	contacts[contact_count].set_contact();
	contact_count++;
}

void	PhoneBook::search_contact()
{
	int	index;
	std::cout << "Choose a contact between 1 and 8" << std::endl;
	std::cin >> index;
	if (index >= 1 && index <= 8)
		contacts[index - 1].print(index);
	else
		std::cerr << "naughty boi! you're being sent back to the home menu!" << std::endl;
    std::cin.ignore(INT16_MAX, '\n');
}

