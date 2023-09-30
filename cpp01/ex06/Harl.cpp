#include <Harl.hpp>

void	Harl::debug(void)
{
	std::cout << "\n[ DEGUB ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\n[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here ";
	std::cout << "since last month." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\n[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}


void	Harl::error(void)
{
	std::cout << "\n[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

void	Harl::cantComplain(void)
{
	std::cout << "Harl complains a lot, its enough!" << std::endl;
}

void	Harl::setPtrs(void)
{
	*funcPtr = &Harl::debug;
	*(funcPtr + 1) = &Harl::info;
	*(funcPtr + 2) = &Harl::warning;
	*(funcPtr + 3) = &Harl::error;
	*(funcPtr + 4) = &Harl::cantComplain;
}

void	Harl::complain(std::string level)
{
	char		firstLetter = *level.c_str();

	switch (firstLetter)
	{
		case 'D':
			(this->*funcPtr[0])();
		case 'I':
			(this->*funcPtr[1])();
		case 'W':
			(this->*funcPtr[2])();
		case 'E':
			(this->*funcPtr[3])();
			break ;
		default:
			(this->*funcPtr[4])();
			break ;
	}
}
