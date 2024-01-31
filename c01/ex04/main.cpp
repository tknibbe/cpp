#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "please provide the name of the file, string to replace and string to replace with" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << "Error opening infile. please check if filename is correct" << std::endl;
		return 1;
	}

	std::ofstream outfile;
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Error opening outfile." << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string temp;
	while (true)			//adds newline at EOF if its not there. fix 
	{
		std::getline(infile, temp);
		if (infile.eof() && temp.empty())
			break ;
		if (s1 == temp)
			outfile << s2 << std::endl;
		else
			outfile << temp << std::endl;
		temp.clear();
	}
	return 0;
}