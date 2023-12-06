#include "PhoneBook.hpp"
#include "Contact.hpp"

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
			return (0);
		}
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "ADD")
			PhoneBook.add_contact();
		else if (input == "SEARCH")
			PhoneBook.search_contact();
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}

