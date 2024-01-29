#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <cstring>
#include <string>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		static void	convert(const std::string& str);

	class InvalidInputException : public std::exception
	{
		private:
			const char	*err;
		public:
			InvalidInputException(const char* err) : err(err) {}
			const char*	what() const throw() { return (err); }
	};
};

void		parseStr(std::string& str);
bool		checkSign(const std::string& trimmed);
bool		stoiHandmade(const std::string& str, int& intNum);
std::string	strtrim(const std::string& str, const std::string& set);

#endif
