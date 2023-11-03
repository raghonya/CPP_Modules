#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("John"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}

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
