#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdio>
# include <cstdlib>

class Contact
{

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSec;
public:
	Contact (void);
	void	setInfo (std::string info, std::string type);
	void	printContactInfo (void);
	void	printAllContacts (int index);

};

#endif