#include "Intern.hpp"

Intern::Intern()
{
	*(this->f) = &Intern::shrubberryCreation;
	*((this->f) + 1) = &Intern::robotomyCreation;
	*((this->f) + 2) = &Intern::presidentialCreation;
	*((this->f) + 3) = &Intern::wrongForm;
}

Intern::Intern(const Intern& other) { (void)other; }

Intern&	Intern::operator=(const Intern& other) { (void)other; return (*this); }

Intern::~Intern() {}

AForm*	Intern::makeForm(const std::string& formType, const std::string& target) const
{
	int	i = 0;
	std::string	formTypes[3] = {"shrubberry", "robotomy", "presidential"};

	for (; i < 3 && formType.compare(formTypes[i]); ++i)
		;
	return ((this->*f[i])(target));
}

AForm*	Intern::shrubberryCreation(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::robotomyCreation(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::presidentialCreation(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::wrongForm(const std::string& target) const
{
	(void)target;
	throw FormDoesntExist();
}
