#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : name("unknown"), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : name(target), gradeToSign(145), gradeToExecute(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << "Creating ASCII tree..." << std::endl;
}
