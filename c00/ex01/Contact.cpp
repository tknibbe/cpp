/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:04 by tknibbe           #+#    #+#             */
/*   Updated: 2024/01/19 16:06:00 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

Contact::Contact(void){
}

Contact::~Contact(void){
	
}

void	Contact::SetContact(void){
	std::string s;

	while (s.empty())
	{
		std::cout << "please input first name:" << std::endl;
		std::getline(std::cin, s);
		if (std::cin.eof())
			exit(1);
	}
	first_name = s;
	
	s.clear();
	while (s.empty())
	{
		std::cout << "please input last name:" << std::endl;
		std::getline(std::cin, s);
		if (std::cin.eof())
			exit(1);
	}
	last_name = s;
	
	std::cout << "please input nickname:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(1);
	nickname = s;
	
	s.clear();
	while (s.empty())
	{
		std::cout << "please input phone number:" << std::endl << "06-";
		std::getline(std::cin, s);
		if (std::cin.eof())
			exit(1);
	}
	phone_number = "06-" + s;
	
	std::cout << "please input " << first_name << "'s darkest secret" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(1);
	secret = s;
}

std::string FitString(std::string input){
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	else
		return (input.insert(0, 10 - input.length(), ' '));
}

void	Contact::Print(){
	if (first_name.empty())
	{
		std::cout << "no contact found" << std::endl;
		return ;
	}
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nick name: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

void	Contact::PrintUi(int index){
	std::cout << "|         " << index;
	std::cout << "|" << FitString(first_name);
	std::cout << "|" << FitString(last_name);
	std::cout << "|" << FitString(nickname) << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
