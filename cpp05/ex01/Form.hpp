#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form();
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();
	public:
		Form(const std::string name, const int gTS, const int gTE);
		std::string			getName() const;
		bool				getSign() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bro);

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

std::ostream&	operator<<(std::ostream& stream, const Form& form);

#endif