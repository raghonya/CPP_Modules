#include "Character.hpp"

Character::Character()
{
	// std::cout << "Character's default constructor called" << std::endl;
	this->name = "person";
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

Character::Character(std::string name)
{
	// std::cout << "Character's parameter constructor called" << std::endl;
	this->name = name;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = nullptr;
}

Character::Character(const Character& other)
{
	// std::cout << "Character's copy constructor called" << std::endl;
	this->name = other.name;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = other.inventory[i];
}

Character& Character::operator=(const Character& other)
{
	// std::cout << "Character's assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	this->name = other.name;

	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
	delete[] this->inventory;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = other.inventory[i];
	
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character's destructor called" << std::endl;

	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
	delete[] this->inventory;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int		i = 0;

	while (i < 4 && this->inventory[i])
		i++;
	if (i < 4)
		this->inventory[i] = m;
	else
		std::cout << "Inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		std::cout << "Materia doesn't exist" << std::endl;
	else
		this->inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		std::cout << "Materia doesn't exist" << std::endl;
	else
		this->inventory[idx]->use(target);
}