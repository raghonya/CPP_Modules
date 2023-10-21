#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FlagTrap : public ClapTrap
{
	public:
		FlagTrap();
		FlagTrap(std::string name);
		FlagTrap(const FlagTrap& bro);
		FlagTrap&	operator=(const FlagTrap& bro);
		~FlagTrap();
	public:
		void	highFivesGuys( void ) const;
		void 	attack(const std::string& target);
};

#endif