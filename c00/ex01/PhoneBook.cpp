/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:01 by tknibbe           #+#    #+#             */
/*   Updated: 2023/10/25 15:39:53 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
}

PhoneBook::~PhoneBook(void){
}

void PhoneBook::add_contact(void)
{
	static int	contact_count = 0;

	if (contact_count > 7)
		contact_count = 0;
	std::cout << "adding :)" << contact_count << std::endl;
	contacts[contact_count].set_contact();
	contact_count++;
}

void	PhoneBook::search_contact(void)
{
	int	index;
	print_all();
	std::cout << "Choose a contact between 1 and 8" << std::endl;
	std::cin >> index;
	if (index >= 1 && index <= 8)
		contacts[index - 1].print();
	else
		std::cerr << "naughty boi! you're being sent back to the home menu!" << std::endl;
    std::cin.ignore(INT16_MAX, '\n');
}

void	PhoneBook::print_all(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].print_ui(i + 1);
}