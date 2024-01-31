#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	char			*barev;
	int				**hajox;
	unsigned short	lav;
};

class Serializer
{
	private:
		Serializer() {};
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);	
};

#endif