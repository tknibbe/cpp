#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>


int main()
{
	PhoneBook PhoneBook;
	std::string input;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 1;
		}
		for (int i=0; i < (int)input.length(); i++)
			input[i] = std::toupper(input[i]);
		if (input == "ADD")
			PhoneBook.AddContact();
		else if (input == "SEARCH")
			PhoneBook.SearchContact();
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 1;
}

