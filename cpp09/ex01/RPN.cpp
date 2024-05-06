#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN& other) { this->arr = other.arr; }
RPN&	RPN::operator=(const RPN& other) { this->arr = other.arr; return (*this); }
RPN::~RPN() {}

// "4 8 + 2 - 6 7 *"
void	RPN::parse(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+' \
		&& str[i] != '-' && str[i] != '*' && str[i] != '/')
		{
			throw std::invalid_argument("Undefined symbols in operation");
		}
		if (str[i + 1] && str[i] != '0' && std::isdigit(str[i]) && std::isdigit(str[i + 1]))
			throw std::invalid_argument\
			("The numbers used as arguments will always be less than 10. ");
	}
}

double	RPN::operation(std::string str)
{
	double	result = 0.0;

	for	(size_t index = str.find_first_not_of(' '); \
		index != str.npos; index = str.find_first_not_of(' '))
	{
		if (std::isdigit(str[index]))
			arr.push(str[index] - '0');
		else
		{
			if (arr.size() < 2)
				throw std::invalid_argument("Invalid input");
			double	second = arr.top();
			arr.pop();
			double	first = arr.top();
			arr.pop();
			// PARSE ANEL STRINGY VOR URISH BAN CHGA
			std::cout << first << str[index] << second << std::endl;
			switch(str[index])
			{
				case '+':
					result = first + second;
					break; 
				case '-':
					result = first - second;
					break; 
				case '*':
					result = first * second;
					break; 
				case '/':
					if (!second)
						throw std::invalid_argument("Division by zero is forbidden!!!");
					result = first / second;
					break;
			}
			arr.push(result);
		}
		str = str.substr(index + 1);
	}
	if (arr.size() > 1)
		throw (std::invalid_argument("Invalid argument"));

	return (result);
}
