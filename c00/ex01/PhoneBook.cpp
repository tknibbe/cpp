/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:01 by tknibbe           #+#    #+#             */
/*   Updated: 2024/01/19 16:04:17 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

#ifndef UINT16_MAX
# define UINT16_MAX 32767
#endif

PhoneBook::PhoneBook(void){
}

PhoneBook::~PhoneBook(void){
}

void PhoneBook::AddContact(void)
{
	static int	contact_count = 0;

	if (contact_count > 7)
		contact_count = 0;
	contacts[contact_count].SetContact();
	contact_count++;
}

void	PhoneBook::SearchContact(void)
{
	std::string	index;
	PrintAll();
	std::cout << "Choose a contact between 1 and 8" << std::endl;
	std::cin >> index;

	if (std::cin.eof())
		exit(1);
	if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
		contacts[index[0] - '1'].Print();
	else
		std::cerr << "naughty naughty! you're being sent back to the home menu!" << std::endl;
	std::cin.ignore(UINT16_MAX, '\n');
}

void	PhoneBook::PrintAll(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].PrintUi(i + 1);
}