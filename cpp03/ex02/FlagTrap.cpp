#include "FlagTrap.hpp"

FlagTrap::FlagTrap() { std::cout << "FlagTrap default constructor called" << std::endl; }

FlagTrap::FlagTrap(std::string name)
{
	std::cout << "FlagTrap parameter constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 100;
	this->attackDamage = 30;
}

FlagTrap::FlagTrap(const FlagTrap& bro) : ClapTrap(bro)
{
	std::cout << "FlagTrap copy constructor called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->energy = bro.energy;
	this->attackDamage = bro.attackDamage;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& bro)
{
	std::cout << "FlagTrap assignment operator called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->energy = bro.energy;
	this->attackDamage = bro.attackDamage;
	return (*this);
}

void 	FlagTrap::attack(const std::string& target)
{
	if (this->energy && this->hp)
	{
		std::cout << "FlagTrap " << this->name << " attacks " << target \
		<< ", causing " << this->attackDamage <<  " points of damage!" << std::endl;
		this->energy -= 1;
	}
	else
		std::cout << "FlagTrap " << this->name << \
		" has not enough energy to attack( or dead :) )!!!" << std::endl;
}

void	FlagTrap::highFivesGuys(void) const
{
	if (this->energy && this->hp)
		std::cout << "High five :):):):):):):):):):)" << std::endl;
	else
		std::cout << "FlagTrap " << this->name \
		<< " has not enough energy to 'high five'( or dead :) )!!!" << std::endl;
}

FlagTrap::~FlagTrap() { std::cout << "FlagTrap destructor called" << std::endl; }