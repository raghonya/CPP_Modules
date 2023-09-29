#include <HumanA.hpp>
#include <Weapon.hpp>

HumanA::HumanA(std::string name,Weapon& wp)
{
	this->name = name;
	this->weapon = &wp;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}