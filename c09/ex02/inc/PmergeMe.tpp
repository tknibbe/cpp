#include "PmergeMe.hpp"

#include <algorithm>
#include <iterator>

template <typename Container>
PmergeMe<Container>::PmergeMe(std::vector<std::string> args){
	for (std::string str : args)
	{
		try
		{
			int	item = std::stoi(str);
			if (item < 0)
			{
				std::cerr << "Argument is not a positive integer\n";
				exit(1);
			}
			if (std::find(_container.begin(), _container.end(), item) != _container.end())
			{
				std::cerr << "Error, duplicate found\n";
				exit(1);
			}
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << "Argument " << str << " is invalid for conversion\n";
			exit(1);
		}
		catch (std::out_of_range &e)
		{
			std::cerr << "Argument " << str << " is out of range of an integer\n";
			exit(1);
		}

		_container.push_back(std::stoi(str));
	}
}


template <typename Container>
std::list<std::pair<int, int>>	PmergeMe<Container>::PmergeMe::createAndSortPairs()
{
	std::list<std::pair<int, int> > list;

	auto item = _container.begin();
	//iterate over the items 
	while (item != _container.end() && std::next(item) != _container.end())
	{
		//set item2 to item+1
		auto item2 = std::next(item);

		//sort the pairs on largest first and add to list
		*item > *item2 ? list.push_back(std::make_pair(*item, *item2)) : list.push_back(std::make_pair(*item2, *item));
			
		//set item to item2+1
		item = std::next(item2);
	}

	return list;
}

template <typename Container>
void	PmergeMe<Container>::PmergeMe::sort()
{
	//return is length is only 1 and by definition sorted
	if (_container.size() == 1)
		return ;

	//check for trailing int (aka uneven lengt)
	bool	hasTrailingNum = false;
	int		trailingNum;

	if (_container.size() % 2)
	{
		hasTrailingNum = true;
		trailingNum = _container.back();
		_container.pop_back();
	}


	//make pairs and immediately sort on biggest first
	std::list<std::pair<int, int>> list = createAndSortPairs();

	//recursively sort the pairs larger numbers

	//insertion sort the lower numbers in?
	//lower_bound uses the binary search so saves code

	//insert the trailingnum somewhere
}

template <typename Container>
void PmergeMe<Container>::PmergeMe::print()
{
	for (auto item : _container)
		std::cout << item << " ";
	std::cout << std::endl;
}