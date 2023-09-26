#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
	PhoneBook	book;
	int			number = 0;

	while (true)
	{
		std::string input;

		if (number > 7)
			number = 0;
		std::cout << "Enter commands ADD, SEARCH, or EXIT\n";
		getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cout << "Cin failed!!!\n";
			return (0);
		}
		if (input.compare("EXIT") == 0)
			return (0);
		else if (input.compare("ADD") == 0)
		{
			book.add_contact(number++);
		}
		else if (input.compare("SEARCH") == 0)
			book.search_contact(number);
	}
	return (0);
}