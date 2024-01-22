#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();
	public:
		AForm*	makeForm(const std::string& formType, const std::string& target) const;
		AForm*	(Intern::*f[4]) (const std::string& target) const;
		AForm*	shrubberryCreation(const std::string& target) const;
		AForm*	robotomyCreation(const std::string& target) const;
		AForm*	presidentialCreation(const std::string& target) const;
		AForm*	wrongForm(const std::string& target) const;

		class FormDoesntExist : public std::exception
		{
			public:
				const char* what() const throw() { return ("Invalid form type"); }
		};
};

#endif
