#include "BitcoinExchange.hpp"
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <map>

std::string	strtrim(std::string str)
{
    str.erase(str.find_last_not_of("\t\n ") + 1);
    str.erase(0, str.find_first_not_of("\t\n "));
    return (str);
}

bool	isdigitStr(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

void	daysInMonthCheck(const std::string &str, int year, int month)
{
	int	day = std::atoi(str.c_str());

	if (str.length() != 2 || day < 1)
		throw std::invalid_argument("Invalid day of month");
	switch (month)
	{
		case (1): case (3): case (5): case (7): \
		case (8): case (10): case (12): 
			if (day > 31)
				throw std::invalid_argument("Invalid day of month");
			break ;
		case (2):
			if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
				throw std::invalid_argument("Be careful with days of February :)");
			break ;
		case (4): case (6): case (9): case (11):
			if (day > 30)
				throw std::invalid_argument("Invalid day of month");
			break ;
	}
}

void	checkDate(const std::string& date)
{
	std::stringstream	dateParse(date);
	std::string			part;
	int					year = 0, month = 0;
	int					iter = 0;

	while (getline(dateParse, part, '-'))
	{
		++iter;
		if (!isdigitStr(part))
			throw std::invalid_argument("Invalid date type");
		switch (iter)
		{
			case (1):
				year = std::atoi(part.c_str());
				break ;
			case (2):
				month = std::atoi(part.c_str());
				if (part.length() != 2 || month < 1 || month > 12)
					throw std::invalid_argument("Invalid date type");
				break ;
			case (3):
				daysInMonthCheck(part, year, month);
				break ;
		}
	}
	if (iter != 3) throw std::invalid_argument("Invalid date type");

}

void	checkValue(const std::string &value, bool isDatabase)
{
	std::stringstream	priceParse(value);
	std::string			part;
	int					iter = 0;

	if (isDatabase && std::atof(value.c_str()) < 0.0)
		throw std::invalid_argument("Invalid BTC value in data.csv file, 0 <= value");
	else if (!isDatabase && \
			(std::atof(value.c_str()) < 0.0 || std::atof(value.c_str()) > 1000.0))
		throw std::invalid_argument("Invalid value in input file, 0 <= value <= 1000");
		
	while (getline(priceParse, part, '.'))
	{
		++iter;
		if (!isdigitStr(part))
			throw std::invalid_argument("Undefined symbols in value");
	}
	if (iter > 2)
		throw std::invalid_argument("Invalid BTC value in data.csv file");

}

void	fileFormatCheck(char *filename, const char *correctFormat)
{
	char	*fileFormat = strrchr(filename, '.');

	if (!fileFormat || strcmp(fileFormat, correctFormat))
		throw std::invalid_argument\
		("Invalid file format for file " + (std::string)filename + \
		", needs format " + correctFormat);
}

void	databaseParse(char *filename, std::map<std::string, float> &database)
{
	std::ifstream		dataFileStream(filename);
	std::string			line;

	fileFormatCheck(filename, (const char *)(".csv"));
	if (dataFileStream.fail())
		throw std::invalid_argument("Database file doesnt exist");

	std::string	date, value;
	while (getline(dataFileStream, line))
	{
		// DATE
		size_t	index = line.find_first_of(',');
		if (index == line.npos)
			throw std::invalid_argument("Invalid data.csv file: Comma error");
		date = line.substr(0, index);

		checkDate(strtrim(date));
		
		// PRICE 
		if (index != line.find_last_of(','))
			throw std::invalid_argument("Invalid data.csv file: Comma error");
		index = line.find_last_of(',');
		value = line.substr(index + 1);

		checkValue(strtrim(value), true);

		// INSERT TO DATABASE
		database.insert(std::pair<std::string, float>(date, std::atof(value.c_str())));
	}
}

void	printValues(std::ifstream &inputFileStream)
{
	std::string	inputLine, inputDate, inputValue;

	while (getline(inputFileStream, inputLine))
	{
		try
		{
			// DATE
			size_t	index = inputLine.find_first_of('|');
			if (index == inputLine.npos)
				throw std::invalid_argument("Invalid input line: Pipe error");
			inputDate = inputLine.substr(0, index);

			checkDate(strtrim(inputDate));
			
			// VALUE
			if (index != inputLine.find_last_of('|'))
				throw std::invalid_argument("Invalid input line: Pipe error");
			index = inputLine.find_last_of('|');
			inputValue = inputLine.substr(index + 1);

			checkValue(strtrim(inputValue), false);
			// std::cout << inputLine << " => " << database << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage of program" << std::endl;
		std::cout << "./btc " << std::endl;
		std::cout << "`Database file in format .csv` " << std::endl;
		std::cout << "`File in format .txt`" << std::endl;
		std::cout << "Database file format: `data , price`" <<std::endl;
		std::cout << "Input file format: `data | value`" <<std::endl;
		return (1);
	}
	try
	{
		std::map<std::string, float>	database;
		std::ifstream					inputFileStream;
		std::string						inputLine;

		databaseParse(argv[1], database);

		fileFormatCheck(argv[2], ".txt");
		inputFileStream.open(argv[2]);
		if (inputFileStream.fail())
			throw std::invalid_argument("Input file doesnt exist");

		for (std::map<std::string, float>::iterator beg = database.begin(); 
		beg != database.end(); ++beg)
			std::cout << beg->first << " and " << beg->second << std::endl;

		printValues(inputFileStream);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
