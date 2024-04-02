#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN& other) { this->arr = other.arr; }
RPN&	RPN::operator=(const RPN& other) { this->arr = other.arr; return (*this); }
RPN::~RPN() {}

int	RPN::operation(std::string str)
{
	int			result = 0;

	std::cout << (int)'+' << " " << (int)'-' << " " << (int)'/' << " " << (int)'*' << std::endl;
	for	(size_t index = str.find_first_not_of(' '); \
		index != str.npos; index = str.find_first_not_of(' '))
	{
		if (std::isdigit(str[index]))
			arr.push(str[index] - '0');
		else
		{
			if (arr.size() < 2)
				throw std::invalid_argument("Invalid input");
			int	second = arr.top();
			arr.pop();
			int	first = arr.top();
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

	return (result);
}
