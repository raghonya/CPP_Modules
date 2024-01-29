#include "ScalarConverter.hpp"
#include <cerrno>
#include <sstream>
void	printNumbers(const std::string& str)
{
	int	intNum = 0, overflow;
	float	floatNum = atof(str.c_str());
	
	// For float and double types
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

	/*
	ete ket chka f chka : 222
	ete ket chka f ka : 222
	ete .0 ka f chka : 222
	ete .0 ka f ka : 222
	ete ket ka f ka : 222.4
	ete ket ka f chka : 222.4
	*/

	std::cout << floatNum;
	if (!strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e'))
		std::cout << ".0f";
	else if (strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e'))
		std::cout << "f";
	std::cout << std::endl;

	// Double
	std::cout << "Double: ";
	std::cout << static_cast<double>(floatNum);
	if (!strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e'))
		std::cout << ".0";
	// else if (strchr(str.c_str(), '.') && fof != "inf" && !strchr(fof.c_str(), 'e'))
	// 	std::cout floatNum;
	// if (overflow)
	// 	std::cout << "Overflow";
	// else if (!strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
	// 	std::cout << str << ".0";
	// else if (!strchr(str.c_str(), '.') && str[str.length() - 1] == 'f')
	// 	std::cout << str.substr(0, str.length() - 1) << ".0";
	// else if (strchr(str.c_str(), '.') && str[str.length() - 1] != 'f')
	// 	std::cout << str;
	// else
	// 	std::cout << str.substr(0, str.length() - 1);
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