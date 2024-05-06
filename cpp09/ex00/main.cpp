#include "BitcoinExchange.hpp"
#include <fstream>

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

bool	argumentCheck(int argc)
{
	if (argc != 3)
	{
		std::cout << "Usage of program" << std::endl;
		std::cout << "./btc ";
		std::cout << "`Database file in format .csv` ";
		std::cout << "`File in format .txt`" << std::endl;
		std::cout << "Database file format: `data , price`" <<std::endl;
		std::cout << "Input file format: `data | value`" <<std::endl;
		return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	if (argumentCheck(argc))
		return (1);
	try
	{
		BitcoinExchange	btc;
		std::ifstream	inputFileStream;

		btc.databaseParse(argv[1]);
		btc.fileFormatCheck(argv[2], ".txt");
		inputFileStream.open(argv[2]);
		if (inputFileStream.fail())
			throw std::invalid_argument("Input file doesnt exist");
		btc.printValues(inputFileStream);
	}
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	return (0);

}
