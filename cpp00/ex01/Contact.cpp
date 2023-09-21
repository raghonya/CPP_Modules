#include <Contact.hpp>

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