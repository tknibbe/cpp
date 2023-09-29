#include <iostream>
#include <bits/stdc++.h> // mag dit?

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	
	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}