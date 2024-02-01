#include "ScalarConverter.hpp"
#include <sstream>

bool	checkAfterDot(const std::string& str)
{
	std::string	check = strchr(str.c_str(), '.');
	int			zeroCount = 0;
	int 		i = 1;

	if (check.c_str() == NULL) return (false);
	for (; check[i] && check[i] == '0'; ++i)
		zeroCount++;
	return (!isdigit(check[i]) || zeroCount > 2);
}

void	printNumbers(const std::string& str)
{
	int	intNum = 0, overflow;
	
	// For float and double types
	float	floatNum = atof(str.c_str());
	std::stringstream ss;
	ss << floatNum << std::endl;
	std::string	fof = ss.str();
	ss.str(std::string());

	overflow = stoiHandmade(str, intNum);
	// Char
	std::cout << "Char: ";
	if ((intNum >= -128 && intNum < 32) || intNum == 127)
		std::cout << "Non-displayable";
	else if (intNum < -128 || intNum > 127)
		std::cout << "Overflow";
	else
		std::cout << "'" << static_cast<char>(intNum) << "'";
	std::cout << std::endl;

	// Int
	std::cout << "Int: ";
	if (overflow)
		std::cout << "Overflow";
	else
		std::cout << intNum;
	std::cout << std::endl;

	// Float
	std::cout << "Float: ";
	std::cout << floatNum;
	if ((!strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e')) \
	|| checkAfterDot(str))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// Double
	std::cout << "Double: ";
	std::cout << static_cast<double>(floatNum);
	if ((!strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e')) \
	|| checkAfterDot(str))
		std::cout << ".0";
	std::cout << std::endl;
}

void	printConverts(const std::string& str)
{
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
		printNumbers(str);
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	if (!str[0])
		throw ScalarConverter::InvalidInputException("Empty input");
	std::string	trimmed = strtrim(str, " \t\n");
	if (strchr(trimmed.c_str(), ' ') || strchr(trimmed.c_str(), '\t')\
	|| strchr(trimmed.c_str(), '\n') || checkSign(trimmed))
		throw ScalarConverter::InvalidInputException("Invalid input type");
	trimmed = strtrim(trimmed, "0");
	parseStr(trimmed);
	printConverts(trimmed);
}