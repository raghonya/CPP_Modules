#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { std::cout << "ClapTrap default constructor called" << std::endl; }

ClapTrap::ClapTrap(std::string name): name(name), hp(10), energy(10), attackDamage(0)
{
	std::cout << "ClapTrap parameter constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& bro)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->attackDamage = bro.attackDamage;
	this->energy = bro.energy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& bro)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	this->name = bro.name;
	this->hp = bro.hp;
	this->attackDamage = bro.attackDamage;
	this->energy = bro.energy;
	return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called!" << std::endl; }

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy && this->hp)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target \
		<< ", causing " << this->attackDamage <<  " points of damage!" << std::endl;
		this->energy -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << \
		" has not enough energy to attack( or dead :) )!!!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp == 0)
	{
		std::cout << "ClapTrap " << this->name << " still dead, cant attack 'them'" << std::endl;
	}
	else if (amount >= this->hp)
	{
		std::cout << "ClapTrap " << this->name << " dies :(" << std::endl;
		this->hp = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " lost " << amount \
		<< " hit points" << std::endl;
		this->hp -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy && this->hp)
	{
		std::cout << "ClapTrap " << this->name << " repair " << amount \
		<<  " hit points!" << std::endl;
		this->hp += amount;
		this->energy -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << \
		" has not enough energy to repair( or dead :) )!!!" << std::endl;
}
