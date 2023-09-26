#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
	PhoneBook	book;

	while (true)
	{
		std::string input;
		int			number = 0;

		if (number > 7)
			number = 0;
		std::cout << "enter commands ADD, SEARCH, or EXIT\n";
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
			number++;
			book.add_contact(number);
		}
		else if (input.compare("SEARCH") == 0)
			book.search_contact(number);
		// printf ("ban\n");
	}
	return (0);
}