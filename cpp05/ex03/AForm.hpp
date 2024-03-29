#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		AForm();
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual	~AForm();
	public:
		AForm(const std::string name, const int gTS, const int gTE);
		virtual	std::string	getName() const;
		virtual	bool		getSign() const;
		virtual	int			getGradeToSign() const;
		virtual	int			getGradeToExecute() const;
		virtual void		beSigned(const Bureaucrat& bro) = 0;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
		class FormIsntSigned : public std::exception
		{
			public:
				const char* what() const throw() { return ("Form isn`t signed"); }
		};

		class FormIsSigned : public std::exception
		{
			public:
				const char* what() const throw() { return ("this form is already signed"); }
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade is too low"); }
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade is too high"); }
		};
};

std::ostream&	operator<<(std::ostream& stream, const AForm& AForm);

#endif