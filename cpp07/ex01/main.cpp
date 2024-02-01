#include "Iter.hpp"

void	f1(int& a)
{
	a %= 3;
}

void	f2(std::string& hlo)
{
	hlo.append(".mp3");
}

int	main()
{
	int arr1[7] = {4, 3, 234, 283, 83, 03, 88};
	iter(arr1, 7, &f1);

	std::string arr2[5] = {"Aram", "Asatryan", "help", "4", "Amanorya"};
	iter(arr2, 5, &f2);

	for (int i = 0; i < 7; ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < 5; ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	
	return (0);
}