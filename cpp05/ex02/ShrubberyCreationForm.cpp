#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("unknown", 145, 137), name("unknown"), gradeToSign(145), gradeToExecute(137) {std::cout << "baaaaaan1\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target, 145, 137), name(target), gradeToSign(145), gradeToExecute(137) {std::cout << "baaaaaan2\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) { (void)other; std::cout << "baaaaaan3\n";}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) { (void)other; return (*this); }

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << "yani xi " << this->name << " " << " " << this->gradeToSign << " " << this->gradeToExecute << " " << this->sign << std::endl;
	if (!this->sign)
		throw FormIsntSigned();
	if (executor.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	std::cout << "Creating ASCII tree..." << std::endl;
	
	int height = 10;

    for (int i = 0; i < height; ++i)
	{
        for (int j = 0; j < height - i - 1; ++j) {
            std::cout << " ";
        }

        for (int k = 0; k < 2 * i + 1; ++k) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < height / 3; ++i) {
        for (int j = 0; j < height - 1; ++j) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }
}
