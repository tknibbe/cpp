/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:01 by tknibbe           #+#    #+#             */
/*   Updated: 2023/09/29 12:04:02 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <bits/stdc++.h> // mag dit?
# include "Phonebook.hpp"


void	valid_and_exec(std::string s, Phonebook pb)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	if (s == "ADD")
		pb.add_contact();
	else if (s == "SEARCH")
		pb.search_contact();
	else if (s == "EXIT")
		exit(0);
	else
		std::cerr << "wrong input, try one of the ones provided maybe??? wtf" << std::endl;
}

void Phonebook::add_contact()
{
	if (contact_count > 7)
		contact_count = 0;
	std::cout << "adding :)" << std::endl;
	contacts[contact_count].set_contact();
}

void	Phonebook::search_contact()
{
	int	x;
	std::cout << "Choose a contact between 1 and 8" << std::endl;
	std::cin >> x;
	if (x >= 1 && x <= 8)
		std::cout << "showing " << x << std::endl;
	else
	{
		std::cin.clear();
		std::cin.
		std::cerr << "naughty boi! you're being sent back to the home menu!" << std::endl;
	}
}

int main(void)
{
	Phonebook	phonebook;
	std::string s;


	std::cout << "Welcome to my phonebook :)" << std::endl;
	while(1)
	{
		std::cout << "please type in what you wnt to do" << std::endl; //give options at some point
		std::cin >> s;
		valid_and_exec(s, phonebook);
	}
	return (0);
}
