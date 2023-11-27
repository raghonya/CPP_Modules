#include "AForm.hpp"

AForm::AForm() : name("contract"), sign(false), gradeToSign(75), gradeToExecute(75) {std::cout << "default AForm\n";}

AForm::AForm(const std::string name, const int gTS, const int gTE): \
name(name), sign(false), gradeToSign(gTS), gradeToExecute(gTE)
{
	if (gTS < 1 || gTE < 1)
		throw GradeTooHighException();
	else if (gTS > 150 || gTE > 150)
		throw GradeTooLowException();
	std::cout << "pARAM AForm\n";
}

AForm::AForm(const AForm& other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm&	AForm::operator=(const AForm& other) { (void)other; return (*this); }

AForm::~AForm() {}

std::string			AForm::getName() const { return (this->name); }
bool				AForm::getSign() const { return (this->sign); }
int					AForm::getGradeToSign() const { return (this->gradeToSign); }
int					AForm::getGradeToExecute() const { return (this->gradeToExecute); }

void	AForm::beSigned(const Bureaucrat& bro)
{
	if (this->sign == true)
		throw FormIsSigned();
	if (bro.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

std::ostream&	operator<<(std::ostream& stream, const AForm& AForm)
{
	stream << "Forms\nName: " << AForm.getName() << "\nSign: " << AForm.getSign() \
	<< "\nGrade to sign: " << AForm.getGradeToSign() << "\nGrade to execute: " \
	<< AForm.getGradeToExecute();

	return (stream);
}
