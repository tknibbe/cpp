/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:31:46 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/11 11:56:20 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong input\n";
		return EXIT_FAILURE;
	}

	std::string input = argv[1];
	for (size_t i = 0; i < input.length(); i++)
		input[i] = tolower(input[i]);

	Harl jan;
	jan.complain(input);
}