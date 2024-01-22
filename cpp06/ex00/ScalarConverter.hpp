#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void	convert(const std::string& str);
		void	inf(const std::string& str) const;
		void	inff(const std::string& str) const;
		void	nan(const std::string& str) const;
		void	(ScalarConverter::*fPtr[3]) (const std::string& str) const;
	class InvalidInputException : public std::exception
	{
		public:
			const char*	what() const throw() { return ("Invalid input"); }
	};
};

#endif