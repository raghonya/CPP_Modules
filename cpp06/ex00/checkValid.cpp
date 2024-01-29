#include "ScalarConverter.hpp"

bool	checkSign(const std::string& trimmed)
{
	std::size_t	plus = trimmed.find('+');
	std::size_t	minus = trimmed.find('-');

	return ((plus != std::string().npos && plus) \
	|| (minus != std::string().npos && minus) ? true : false);
}

bool	stoiHandmade(const std::string& str, int& intNum)
{
	int	sign = 1;
	int	i = 0;
	int	oldNum;

	if (str == "-2147483648")
	{
		intNum = INT_MIN;
		return (false);
	}
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	for (; str[i] && str[i] > 47 && str[i] < 58; ++i)
	{
		oldNum = intNum;
		intNum = (intNum * 10) + (str[i] - '0');
		if (oldNum > intNum)
			return (true);
	}
	intNum = intNum * sign;
	return (false);
}

std::string	strtrim(const std::string& str, const std::string& set)
{
	std::string	trimmed;
	int start = 0, end = str.length() - 1;

	for (int i = 0; str[i] && strchr(set.c_str(), str[i]); ++i)
		start = i + 1;
	for (int i = str.length() - 1; str[i] && set.find('0') == set.npos\
	&& strchr(set.c_str(), str[i]); --i)
		end = i - 1;
	if (str[start] == '+' || str[start] == '-')
	{
		int save = start;
		for (int i = ++start; str[i] && str[i] == '0'; ++i)
			start = i + 1;
		if (str[save] == '+')
			trimmed.push_back('+');
		else
			trimmed.push_back('-');
	}
	for (int i = start; i <= end; ++i)
		trimmed.push_back(str[i]);
	if (!trimmed[0] && strchr(str.c_str(), '0'))
		trimmed = "0";
	// std::cout << "trimmmed: '" << trimmed << "'" << std::endl;
	return (trimmed);
}

void	checkValidStr(const std::string& str)
{
	int i;
	int	digitCount = 0;
	std::string	inputs[8] = {"inf", "-inf", \
	"+inf", "inff", "-inff", "+inff", "nan", "nanf"};
	
	// Member of array `inputs`
	for (i = 0; str[i]; ++i) if (isdigit(str[i])) digitCount++;
	for (i = 0; digitCount == 0 && i < 8; ++i)
		if (str == inputs[i])
			break ;
	if (i == 8)
		throw ScalarConverter::InvalidInputException("Invalid option");
	// Not a member of array `inputs`
	if (digitCount > 0)
	{
		for (i = 0; str[i]; ++i)
			if (strchr("ina", str[i]) || (str[i] == 'f' && i != int(str.length() - 1)))
				throw ScalarConverter::InvalidInputException("Invalid option");
		if (strchr("ina", str[str.length() - 1]))
			throw ScalarConverter::InvalidInputException("Invalid option");
	}
}

void	parseStr(std::string& str)
{
	int	i, dotCount = 0;
	
	for (i = 0; str[i]; ++i)
	{
		if (str[i] == '.')
		{
			if (!str[i + 1] || str[i + 1] == 'f')
				throw ScalarConverter::InvalidInputException("Invalid input");
			if (i == 0 || !std::isdigit(str[i - 1]))
				str.insert(i++, "0");
			dotCount++;
		}
		if ((str[i] != '+' && str[i] != '-' && str[i] != '.' \
		&& !strchr("infa", str[i]) && !std::isdigit(str[i])) \
		|| ((str[i] == '+' || str[i] == '-') && i != 0) || dotCount > 1)
		{
			std::cout << "Error symbol " << str[i] << std::endl;
			throw ScalarConverter::InvalidInputException("Undefined symbol");
		}
	}
	checkValidStr(str);
}
