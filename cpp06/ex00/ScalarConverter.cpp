#include "ScalarConverter.hpp"
#include <cstring>
#include <cstdio>
#include <cstdlib>

std::string	strtrim(const std::string& str)
{
	std::string	trimmed;
	int start = 0, end = str.length() - 1;

	for (int i = 0; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; ++i)
		start = i + 1;
	for (int i = str.length() - 1; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; --i)
		end = i - 1;
	for (int i = start; i <= end; ++i)
		trimmed.push_back(str[i]);
	return (trimmed);
}

void	checkValidStr(const std::string& str)
{
	int i;
	int	digitCount = 0;
	// int	fCount = 0;
	std::string	inputs[8] = {"inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf"};
	
	// Member of array `inputs`
	for (i = 0; str[i]; ++i) if (isdigit(str[i])) digitCount++;
	for (i = 0; digitCount == 0 && i < 8; ++i)
		if (str == inputs[i])
			break ;
	if (i == 8)
		throw ScalarConverter::InvalidInputException();
	// Not a member of array `inputs`
	if (digitCount > 0)
	{
		for (i = 0; str[i]; ++i)
			if (strchr("ina", str[i]) || (str[i] == 'f' && i != int(str.length() - 1)))
				throw ScalarConverter::InvalidInputException();
		if (strchr("ina", str[str.length() - 1]))
			throw ScalarConverter::InvalidInputException();
	}
}

void	parse_str(std::string& str)
{
	int	i, dotCount = 0;
	
	for (i = 0; str[i]; ++i)
	{
		if (str[i] == '.')
		{
			if (!str[i + 1] || str[i + 1] == 'f')
				throw ScalarConverter::InvalidInputException();
			if (i == 0 || !std::isdigit(str[i - 1]))
				str.insert(i++, "0");
			dotCount++;
		}
		if ((str[i] != '+' && str[i] != '-' && str[i] != '.' \
		&& !strchr("infa", str[i]) && !std::isdigit(str[i])) \
		|| ((str[i] == '+' || str[i] == '-') && i != 0) || dotCount > 1)
		{
			std::cout << "Error symbol " << str[i] << std::endl;
			throw ScalarConverter::InvalidInputException();
		}
	}
	checkValidStr(str);
}

void	print_converts(const std::string& str)
{
	int		intNum;

	sscanf(str.c_str(), "%d", &intNum);
	if (strchr(str.c_str(), 'n'))
	{

		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;

		std::cout << "Float: " << str;
		if (str != "nanf" && \
		(!strchr(str.c_str(), 'f') || !strcmp(strchr(str.c_str(), 'f'), "f")))
			std::cout << 'f';
		std::cout << std::endl;
		
		std::cout << "Double: ";
		if (str != "inf" && str != "+inf" \
		&& str != "-inf" && str[str.length() - 1] == 'f')
			std::cout << str.substr(0, str.length() - 1);
		else
			std::cout << str;
		std::cout << std::endl;
	}
	else
	{
		// Char
		std::cout << "Char: ";
		if (intNum < 32 || intNum > 127)
			std::cout << "Non-displayable" << std::endl;
		else
			std::cout << "'" << (char)intNum << "'" << std::endl;

		// Int
		std::cout << "Int: " << intNum << std::endl;

		// Float
		std::cout << "Float: ";
		if (!strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
			std::cout << str << ".0f";
		else if (!strchr(str.c_str(), '.') && str[str.length() - 1] == 'f')
			std::cout << str.substr(0, str.length() - 1) << ".0f";
		else if (strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
			std::cout << str << 'f';
		else 
			std::cout << str;
		std::cout << std::endl;

		// Double
		std::cout << "Double: ";
		if (!strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
			std::cout << str << ".0";
		else if (!strchr(str.c_str(), '.') && str[str.length() - 1] == 'f')
			std::cout << str.substr(0, str.length() - 1) << ".0";
		else if (strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
			std::cout << str;
		else
			std::cout << str.substr(0, str.length() - 1);
		std::cout << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	if (!str[0])
	{
		std::cout << "Empty string, ..." << std::endl;
		return ;
	}
	std::string	trimmed = strtrim(str);
	parse_str(trimmed);
	print_converts(trimmed);
}