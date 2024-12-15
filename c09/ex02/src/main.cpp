#include "../inc/PmergeMe.hpp"

#include <iostream>
#include <unistd.h>
#include <chrono>

int	g_comparison_count = 0;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error, not enough arguments given\n";
		return (1);
	}

	argv++;
	std::vector<std::string> args(argv, argv + argc - 1);

	auto begin = std::chrono::high_resolution_clock::now();

	PmergeMe<> VectorClass(args);
	VectorClass.FordJohnsonSort();

	auto end = std::chrono::high_resolution_clock::now();


	std::cout << "Before: ";
	for (std::string str : args)
		std::cout << str << " ";
	
	std::cout << "\nAfter : ";
	VectorClass.print();

	std::cout << "Time to process a range of " << argc -1 << " elements with std::vector : " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " us\n";

	g_comparison_count = 0;
	begin = std::chrono::high_resolution_clock::now();;
	PmergeMe<std::list<int>>	listClass(args);
	listClass.FordJohnsonSort();
	end = std::chrono::high_resolution_clock::now();
	// std::cout << "\nAfter : ";
	// listClass.print();

	std::cout << "Time to process a range of " << argc -1 << " elements with std::list   : " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " us\n";


	std::cout << "\nThis program made (taken worst case to be sure) " << g_comparison_count << " comparisons.\n(check main to make sure g_comparison_count gets reset after every sort so it doesnt over-count)\n";
}