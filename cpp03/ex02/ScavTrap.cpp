#include "ScavTrap.hpp"

ScavTrap::ScavTrap() { std::cout << "ScavTrap default constructor called" << std::endl; }

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap parameter constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& bro) : ClapTrap(bro)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->energy = bro.energy;
	this->attackDamage = bro.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& bro)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->energy = bro.energy;
	this->attackDamage = bro.attackDamage;
	return (*this);
}

void	ScavTrap::guardGate(void) const
{
	if (this->energy && this->hp)
		std::cout << "ScavTrap " << this->name \
		<< " is now in Gate keeper mode -_-" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << \
		" has not enough energy to guard( or dead :) )!!!" << std::endl;
}

void 	ScavTrap::attack(const std::string& target)
{
	if (this->energy && this->hp)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target \
		<< ", causing " << this->attackDamage <<  " points of damage!" << std::endl;
		this->energy -= 1;
	}
	else
		std::cout << "ScavTrap " << this->name << \
		" has not enough energy to attack( or dead :) )!!!" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }
