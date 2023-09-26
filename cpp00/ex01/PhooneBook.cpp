#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <cstring>

int	checkDigits(std::string info)
{
	size_t i = 0;
	while (i < info.length())
	{
		if (info[i] < 48 || info[i] > 57)
		{
			std::cout << "Enter only digits!!!\n";
			return (1);
		}
		i++;
	}
	return (0);
}

void	PhoneBook::setContact(int number, std::string type)
{
	std::string info;

	while (true)
	{
		std::cout << "Enter " << type << " of user: ";
		getline(std::cin, info);
		if (std::cin.fail())
		{
			std::cout << "Cin failed!!!\n";
			std::exit(1);
		}
		if (type == "phoneNumber" && checkDigits(info))
			continue ;
		if (info != "")
			break ;
	}
	this->users[number].setInfo(info, type);
}

void	PhoneBook::add_contact(int number)
{
	setContact(number, "firstName");
	setContact(number, "lastName");
	setContact(number, "nickName");
	setContact(number, "phoneNumber");
	setContact(number, "darkestSec");
}

void	PhoneBook::search_contact(void)
{
	std::string		input;

	for (int i = 0; i < 8; i++)
		this->users[i].printAllContacts(i);
	while (true)
	{
		std::cout << "Enter index of contact\n";
		getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cout << "Cin failed!!!\n";
			std::exit(1);
		}
		if (input.length() == 1 && strchr("01234567", input[0]))
			break ;
		std::cout << "Index out of range!!!. Try again\n";
	}
	this->users[(strchr("01234567", input[0]))[0] - 48].printContactInfo();
}