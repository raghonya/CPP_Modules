#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	public:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string target);
		std::string			getName() const;
		bool				getSign() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				execute(Bureaucrat const & executor) const;
		void				beSigned(const Bureaucrat& bro);
};

#endif
