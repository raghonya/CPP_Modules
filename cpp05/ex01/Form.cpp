#include "Form.hpp"

Form::Form() : name("contract"), sign(false), gradeToSign(75), gradeToExecute(75) {}

Form::Form(const Form& other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form::Form(const std::string name, const int gTS, const int gTE): \
name(name), sign(false), gradeToSign(gTS), gradeToExecute(gTE)
{
	if (gTS < 1 || gTE < 1)
		throw GradeTooHighException();
	else if (gTS > 150 || gTE > 150)
		throw GradeTooLowException();
}

Form&	Form::operator=(const Form& other) { (void)other; return (*this); }

Form::~Form() {}

std::string			Form::getName() const { return (this->name); }
bool				Form::getSign() const { return (this->sign); }
int					Form::getGradeToSign() const { return (this->gradeToSign); }
int					Form::getGradeToExecute() const { return (this->gradeToExecute); }

void	Form::beSigned(const Bureaucrat& bro)
{
	if (bro.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		std::cout << "Not enough grade to sign document by bro " << bro.getName() << " -_-" << std::endl;
}

// std::ostream& operator<<(std::ostream& stream, const Form& form)
// {
// 	stream << 
// }
