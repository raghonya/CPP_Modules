#include "BitcoinExchange.hpp"
#include <fstream>
#include <map>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage of program" << std::endl;
		std::cout << "./btc ";
		std::cout << "`Database file in format .csv` ";
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
		printValues(inputFileStream, database);
	}
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

}
