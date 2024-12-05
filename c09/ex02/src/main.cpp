#include "../inc/PmergeMe.hpp"

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error, not enough arguments given\n";
		return (1);
	}

	argv++;
	std::vector<std::string> args(argv, argv + argc - 1);


	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);

	PmergeMe<> VectorClass(args);
	VectorClass.sort();

	gettimeofday(&end, NULL);



	std::cout << "Before: ";
	for (std::string str : args)
		std::cout << str << " ";
	
	std::cout << "\nAfter: ";
	VectorClass.print();

	std::cout << "Time to process a range of " << argc -1 << " elements with std::vector : " << end.tv_usec - start.tv_usec << " us\n";


	gettimeofday(&start, NULL);
	PmergeMe<std::list<int>>	listClass(args);
	listClass.sort();
	gettimeofday(&end, NULL);

	std::cout << "Time to process a range of " << argc -1 << " elements with std::list   : " << end.tv_usec - start.tv_usec << " us\n";

}