#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& bro);
		ScavTrap&	operator=(const ScavTrap& bro);
		~ScavTrap();
	public:
		void	guardGate( void ) const;
};

#endif