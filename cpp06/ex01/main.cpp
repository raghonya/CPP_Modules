#include "Serializer.hpp"

int	main()
{
	std::cout << "Mi toxanoc funkcianer" << std::endl;

	Data	*priwet = new(Data);
	// Serializer	smth;

	std::cout << priwet << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(priwet)) << std::endl;

	delete priwet;
	return (0);
}