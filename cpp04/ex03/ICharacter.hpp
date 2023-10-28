#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	private:
		std::string	name;
		// AMateria	**inventory;
	public:
		ICharacter();
		ICharacter(std::string name);
		ICharacter(const ICharacter& other);
		ICharacter&	operator=(const ICharacter& other);
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
