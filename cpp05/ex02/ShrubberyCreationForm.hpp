#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string target);
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(const Bureaucrat& bro);
};

#endif
