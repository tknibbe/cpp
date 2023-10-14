/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:04 by tknibbe           #+#    #+#             */
/*   Updated: 2023/10/14 17:21:50 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void){
}

Contact::~Contact(void){
	
}

void	Contact::set_contact(void)
{
	std::string s;

	std::cout << "please input First name:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);// fix to be continueing
	this->first_name = s;
	
	std::cout << "please input last name:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	this->last_name = s;
	
	std::cout << "please input nickname:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	this->nickname = s;
	
	std::cout << "please input Phone number:" << std::endl << "06-";
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	this->phone_number = "06-" + s;
	
	std::cout << "please input " << this->first_name << "'s darkest secret" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	this->secret = s;
}

std::string fit_str(std::string input)
{
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	else
		return (input.insert(0, 10 - input.length(), ' '));
}

void	Contact::print(int index)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|         " << index;
	std::cout << "|" << fit_str(this->first_name);
	std::cout << "|" << fit_str(this->last_name);
	std::cout << "|" << fit_str(this->nickname) << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}
