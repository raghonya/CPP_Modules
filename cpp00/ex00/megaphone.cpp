#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	int	i = 0, j;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			std::cout << (char)std::toupper(argv[i][j]);
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << "\n";
	return (0);
}
