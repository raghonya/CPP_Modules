#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact users[8];
public:
	void	add_contact(int number);
	void	search_contact(int number);
	void	print_book(int number, std::string type);
	void	setContact(int number, std::string type);
};
