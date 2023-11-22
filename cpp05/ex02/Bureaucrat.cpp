#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("John"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;

	return (*this);
}

Bureaucrat::~Bureaucrat() {};

void	Bureaucrat::incrementGrade( void ) { this->grade -= 1; }

void	Bureaucrat::decrementGrade( void ) { this->grade += 1; }

int		Bureaucrat::getGrade( void ) const { return (this->grade); }

const std::string	Bureaucrat::getName( void ) const { return (this->name); }

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat bro)
{
	stream << bro.getName() << ", bureaucrat grade " << bro.getGrade();

	return (stream);
}
