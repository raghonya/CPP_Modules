#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkestSec = "";
}

void	Contact::setInfo(std::string info, std::string type)
{
	if (type == "firstName")
		this->firstName = info;
	else if (type == "lastName")
		this->lastName = info;
	else if (type == "nickName")
		this->nickName = info;
	else if (type == "phoneNumber")
		this->phoneNumber = info;
	else if (type == "darkestSec")
		this->darkestSec = info;
}

void	Contact::printContactInfo(void)
{
	std::cout << "Contact`s first name: " << this->firstName << std::endl;
	std::cout << "Contact`s last name: " << this->lastName << std::endl;
	std::cout << "Contact`s nick name: " << this->nickName << std::endl;
	std::cout << "Contact`s phone number: " << this->phoneNumber << std::endl;
	std::cout << "Contact`s darkest secret: " << this->darkestSec << std::endl;
}


void	Contact::printAllContacts(int index)
{
	int	spaces;

	// INDEX
	spaces = 1;
	for (; spaces < 10; spaces++)
	{
		std::cout << " ";
	}
	std::cout << index << "|";
	// FIRST NAME
	spaces = this->firstName.length();
	for (; spaces < 10; spaces++)
	{
		std::cout << " ";
	}
	if (this->firstName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->firstName[i];
		std::cout << ".|";
	}
	else
		std::cout << this->firstName << "|";

	// LAST NAME
	spaces = this->lastName.length();
	for (; spaces < 10; spaces++)
	{
		std::cout << " ";
	}
	if (this->lastName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->lastName[i];
		std::cout << ".|";
	}
	else
		std::cout << this->lastName << "|";
	
	// NICK NAME
	spaces = this->nickName.length();
	for (; spaces < 10; spaces++)
	{
		std::cout << " ";
	}
	if (this->nickName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->nickName[i];
		std::cout << ".|";
	}
	else
		std::cout << this->nickName << "|";

	// // PHONE NUMBER
	// spaces = this->phoneNumber.length();
	// for (; spaces < 10; spaces++)
	// {
	// 	std::cout << " ";
	// }
	// if (this->phoneNumber.length() > 10)
	// {
	// 	for(int i = 0; i < 9; i++)
	// 		std::cout << this->phoneNumber[i];
	// 	std::cout << ".|";
	// }
	// else
	// 	std::cout << this->phoneNumber << "|";

	// // DARKEST SECRET
	// spaces = this->darkestSec.length();
	// for (; spaces < 10; spaces++)
	// {
	// 	std::cout << " ";
	// }
	// if (this->darkestSec.length() > 10)
	// {
	// 	for(int i = 0; i < 9; i++)
	// 		std::cout << this->darkestSec[i];
	// 	std::cout << ".|";
	// }
	// else
	// 	std::cout << this->darkestSec << "|";

	std::cout << std::endl;
}