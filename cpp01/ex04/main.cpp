#include <fstream>
#include <iostream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Give 3 arguments" << std::endl;
		return (1);
	}
	std::stringstream	iss;
	std::string 		text;
	std::ifstream		toReplace(argv[1]);
	std::ofstream		replaced((std::string(argv[1]) + ".replace").c_str());

	iss << toReplace.rdbuf();
	toReplace.close();
	text = iss.str();
	size_t	size = 0;
	while (true)
	{
		size = text.find(argv[2], size);
		if (*(argv[2]) && size < text.length())
		{
			text.erase(size, std::string(argv[2]).length());
			text.insert(size, std::string(argv[3]));
			size += std::string(argv[3]).length();
			std::cout << size << " " << text.length() << std::endl;
		}
		else
			break ;
	}
	replaced << text;
	replaced.close();
}