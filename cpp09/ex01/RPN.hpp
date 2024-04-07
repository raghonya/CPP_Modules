#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int>		arr;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
	public:
		int		operation(std::string	str);
		void	parse(const std::string& str);

};

#endif
