#include <Harl.hpp>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here ";
	std::cout << "since last month." << std::endl;
}



void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}


void	Harl::error(void)
{
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;

}

void	Harl::setPtrs(void)
{
	*funcPtr = &Harl::debug;
	*(funcPtr + 1) = &Harl::info;
	*(funcPtr + 3) = &Harl::warning;
	*(funcPtr + 2) = &Harl::error;
}

void	Harl::complain(std::string level)
{
	// this->funcPtr();
}
