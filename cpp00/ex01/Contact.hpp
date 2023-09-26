#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSec;
public:
	Contact(void);
	void	setInfo(std::string info, std::string type);
};
