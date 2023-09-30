#include <Weapon.hpp>
#include <HumanB.hpp>

HumanB::HumanB(std::string name): name(name)
{
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " dont have a weapon :(" << std::endl;
}