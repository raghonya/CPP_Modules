#include <Contact.hpp>
#include <iomanip>

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


void	Contact::printContactList(int index)
{
	std::cout << std::setw(10) << index << "|";
	
	if (this->firstName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->firstName[i];
		std::cout << ".|";
	}
	else
		std::cout << std::setw(10) << this->firstName << "|";
	
	if (this->lastName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->lastName[i];
		std::cout << ".|";
	}
	else
		std::cout << std::setw(10) << this->lastName << "|";
	
	if (this->nickName.length() > 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << this->nickName[i];
		std::cout << ".|";
	}
	else
		std::cout << std::setw(10) << this->nickName << "|";
	
	std::cout << std::endl;
}