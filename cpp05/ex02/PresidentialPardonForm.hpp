#ifndef PPF_HPP
# define PPF_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string target);
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(const Bureaucrat& bro);
};

#endif
