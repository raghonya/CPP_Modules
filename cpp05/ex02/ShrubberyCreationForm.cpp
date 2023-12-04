#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), name("unknown"), sign(false), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(), name(target), sign(false), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bro)
{
	if (this->sign == true)
		throw FormIsSigned();
	if (bro.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->sign = true;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << "Creating ASCII tree..." << std::endl;

	std::string		filename = this->name + (std::string)"_shtubberry";
	std::ofstream	file;
	file.open((this->name + (std::string)"_shrubberry").c_str(), std::ios::out | std::ios::trunc);

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20 - i - 1; ++j)
			file << ' ';
		for (int j = 0; j < i * 2 + 1; ++j)
			file << '*';
		file << std::endl;
	}

	std::cout << "ASCII tree created, check the file \"" << this->name + (std::string)"_shtubberry\"" << std::endl;
}

std::string			ShrubberyCreationForm::getName() const { return (this->name); }
bool				ShrubberyCreationForm::getSign() const { return (this->sign); }
int					ShrubberyCreationForm::getGradeToSign() const { return (this->gradeToSign); }
int					ShrubberyCreationForm::getGradeToExecute() const { return (this->gradeToExecute); }
