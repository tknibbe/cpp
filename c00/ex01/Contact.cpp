/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:04:04 by tknibbe           #+#    #+#             */
/*   Updated: 2023/10/25 15:39:46 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void){
}

Contact::~Contact(void){
	
}

void	Contact::set_contact(void){
	std::string s;

	std::cout << "please input First name:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);// fix to be continueing
	first_name = s;
	
	std::cout << "please input last name:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	last_name = s;
	
	std::cout << "please input nickname:" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	nickname = s;
	
	std::cout << "please input Phone number:" << std::endl << "06-";
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	phone_number = "06-" + s;
	
	std::cout << "please input " << first_name << "'s darkest secret" << std::endl;
	std::getline(std::cin, s);
	if (std::cin.eof())
		exit(EXIT_SUCCESS);
	secret = s;
}

std::string fit_str(std::string input){
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	else
		return (input.insert(0, 10 - input.length(), ' '));
}

void	Contact::print(){
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nick name: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

void	Contact::print_ui(int index){
	std::cout << "|         " << index;
	std::cout << "|" << fit_str(first_name);
	std::cout << "|" << fit_str(last_name);
	std::cout << "|" << fit_str(nickname) << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
