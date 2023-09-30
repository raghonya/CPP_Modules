#include <fstream>
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4 || !*(argv[2]))
	{
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}

	std::stringstream	iss;
	std::string 		text;
	std::ifstream		toReplace(argv[1]);
	std::ofstream		replaced((std::string(argv[1]) + ".replace").c_str());

	if (toReplace.fail() || replaced.fail())
	{
		std::cout << "File stream error!!!" << std::endl;
		return (1);
	}
	iss << toReplace.rdbuf();
	text = iss.str();
	size_t	size = 0;
	while (true)
	{
		size = text.find(argv[2], size);
		if (size >= text.length())
			break ;
		text.erase(size, std::string(argv[2]).length());
		text.insert(size, std::string(argv[3]));
		size += std::string(argv[3]).length();
	}
	replaced << text;
}