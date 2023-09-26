#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <Contact.hpp>

class PhoneBook
{
private:
	Contact users[8];
public:
	void	add_contact(int number);
	void	search_contact(void);
	void	setContact(int number, std::string type);
};

#endif