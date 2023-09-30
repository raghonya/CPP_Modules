#include <HumanA.hpp>
#include <Weapon.hpp>

HumanA::HumanA(std::string name, Weapon& wp): name(name), weapon(wp) { }

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}