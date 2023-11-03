#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();
	public:
		Bureaucrat(const std::string name, int grade);
		void				incrementGrade( void );
		void				decrementGrade( void );
		int					getGrade( void ) const;
		const std::string	getName( void ) const;

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() { return ("Grade is too low"); }
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() { return ("Grade is too high"); }
		};
};

#endif