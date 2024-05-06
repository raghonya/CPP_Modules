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
	public:
		void	databaseParse(char *filename);
		void	checkDate(const std::string& date);
		void	printValues(std::ifstream &inputFileStream);
		void	checkValue(const std::string &value, bool isDatabase);
		void	daysInMonthCheck(const std::string &str, int year, int month);
		void	fileFormatCheck(const char *filename, const char *correctFormat);
		void	parseInputFile(	const std::string inputLine, \
								std::string& inputDate, std::string& inputValue);
};

std::string	strtrim(std::string str);
bool		isdigitStr(const std::string& str);

#endif
