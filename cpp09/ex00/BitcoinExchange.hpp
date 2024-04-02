#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();

};

void	fileFormatCheck(const char *filename, const char *correctFormat);
void	databaseParse(char *filename, std::map<std::string, float> &database);
void	printValues(std::ifstream &inputFileStream, \
					std::map<std::string, float>& database);

#endif
