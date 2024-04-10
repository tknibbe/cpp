/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:25 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 15:57:54 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory address of str: " << &str << std::endl;
	std::cout << "memory address of PTR: " << stringPTR << std::endl;
	std::cout << "memory address of REF: " << &stringREF << std::endl << std::endl;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value of PTR: " << *stringPTR << std::endl;
	std::cout << "value of REF: " << stringREF << std::endl;
}