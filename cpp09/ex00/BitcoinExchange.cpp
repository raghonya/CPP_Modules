#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->database = copy.database;
}
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	this->database = other.database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::fileFormatCheck
(const char *filename, const char *correctFormat)
{
	const char	*fileFormat = strrchr(filename, '.');

	if (!fileFormat || strcmp(fileFormat, correctFormat))
		throw std::invalid_argument\
		("Invalid file format for file " + (std::string)filename + \
		", needs format " + (std::string)correctFormat);
}

void	BitcoinExchange::daysInMonthCheck
(const std::string &str, int year, int month)
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

void	BitcoinExchange::checkDate(const std::string& date)
{
	std::stringstream	dateParse(date);
	std::string			part;
	int					year = 0, month = 0;
	int					iter = 0;

	if (!date[0] || !std::isdigit(date[date.length() - 1]))
		throw std::invalid_argument("Invalid date type");
	while (getline(dateParse, part, '-'))
	{
		++iter;
		if (iter > 3) throw std::invalid_argument("Invalid date type");
		if (!part[0] || !isdigitStr(part))
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
	if (iter < 3) throw std::invalid_argument("Invalid date type");

}

void	BitcoinExchange::checkValue\
(const std::string &value, bool isDatabase)
{
	std::stringstream	priceParse(value);
	std::string			part;
	int					iter = 0;

	if (!value[0] || (isDatabase && std::atof(value.c_str()) < 0.0))
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

void	BitcoinExchange::databaseParse(char *filename)
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
		date = strtrim(date);
		checkDate(date);

		// PRICE 
		if (index != line.find_last_of(','))
			throw std::invalid_argument("Invalid data.csv file: Comma error");
		value = line.substr(index + 1);
		value = strtrim(value);

		checkValue(value, true);

		// INSERT TO DATABASE
		this->database.insert(std::pair<std::string, float>(date, std::atof(value.c_str())));
	}
}

void	BitcoinExchange::parseInputFile\
(const std::string inputLine, std::string& inputDate, std::string& inputValue)
{
	// DATE
	size_t	index = inputLine.find_first_of('|');
	if (index == inputLine.npos)
		throw std::invalid_argument("Invalid input line: Pipe error");
	inputDate = inputLine.substr(0, index);
	inputDate = strtrim(inputDate);
	checkDate(inputDate);
	
	// VALUE
	if (index != inputLine.find_last_of('|'))
		throw std::invalid_argument("Invalid input line: Pipe error");
	inputValue = inputLine.substr(index + 1);
	inputValue = strtrim(inputValue);
	checkValue(inputValue, false);
}

void	BitcoinExchange::printValues(std::ifstream &inputFileStream)
{
	std::string	inputLine, inputDate, inputValue;
	std::map<std::string, float>::iterator iter;
	bool	continueLoop;

	while (getline(inputFileStream, inputLine))
	{
		try
		{
			continueLoop = false;
			parseInputFile(inputLine, inputDate, inputValue);
			for (iter = this->database.begin(); iter != this->database.end(); ++iter)
			{
				if (iter->first == inputDate)
				{
					std::cout << inputDate << " => " << inputValue << " = " << iter->second * atof(inputValue.c_str()) << std::endl;
					continueLoop = true;
					break ;
				}
			}
			if (!continueLoop)
			{
				for (iter = this->database.begin(); iter != this->database.end(); ++iter)
					if (iter->first > inputDate)
						break ;
				if (iter == this->database.begin())
					throw std::invalid_argument("Invalid date in input file");

				std::cout << inputDate << " => " << inputValue << " = " << \
				(--iter)->second * atof(inputValue.c_str()) << std::endl;
			}
		}
		catch (const std::exception& e)	{ std::cout << e.what() << std::endl; }
	}
}
