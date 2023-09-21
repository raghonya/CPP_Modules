#pragma once

#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSec;
public:
	void	setInfo(std::string info, std::string type);
};
