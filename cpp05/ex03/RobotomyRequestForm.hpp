#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"
#include "cstdlib"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string target);
		std::string			getName() const;
		bool				getSign() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				execute(Bureaucrat const & executor) const;
		void				beSigned(const Bureaucrat& bro);
};

#endif
