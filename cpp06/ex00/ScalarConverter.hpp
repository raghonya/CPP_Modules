#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void	convert(const std::string& str);

	class InvalidInputException : public std::exception
	{
		public:
			const char*	what() const throw() { return ("Invalid input"); }
	};
};

#endif