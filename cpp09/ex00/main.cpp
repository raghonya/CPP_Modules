#include "BitcoinExchange.hpp"
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>

bool	isdigitStr(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

void	checkDate(const std::string& date)
{
	std::stringstream	dateParse(date);
	std::string			part;
	int					iter = 0;

	while (getline(dateParse, part, '-'))
	{
		++iter;
		if (!isdigitStr(part))
			throw std::invalid_argument("Invalid date type");
	}
	if (iter != 3)
		throw std::invalid_argument("Invalid date type");

}

void	fileParse(char *file, std::map<std::string, float> &database)
{
	char	*fileFormat = strrchr(file, '.');

	if (!fileFormat || strcmp(fileFormat, ".csv"))
		throw std::invalid_argument("Invalid argument");
	
	std::stringstream	fileStream;
	std::ifstream		inputFile(file);
	std::string			line;

	if (inputFile.fail())
		throw std::invalid_argument("File doesnt exist");

	std::string	date, price;
	while (getline(inputFile, line))
	{
		size_t	index = line.find_first_of(',');
		if (index == line.npos)
			throw std::invalid_argument("Invalid data.csv file");
		date = line.substr(0, index);

		// std::stringstream	dateParse(date);

		// PARSING DATE

		checkDate(date);

		// PARSING DATE END

		// std::cout << date << std::endl;
		// break ;
		index = line.find_last_of(',');
		if (index == line.npos)
			throw std::invalid_argument("Invalid data.csv file");
		price = line.substr(index + 1);
		std::cout << "`" << price << "`" << std::endl;
		break ;
		// database.insert(std::pair<std::string, float>(date, ));
		// <std::string, float>(line.substr(0, line.)));
	}

}

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cerr << \
		"Usage: ./btc `Data file in format .csv` `File in format .txt`" \
		<< std::endl;
		return (1);
	}
	try
	{
		std::map<std::string, float> database;
		fileParse(argv[1], database);
		
		// while ()

		// std::
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// std::cout << a << std::endl;

}
