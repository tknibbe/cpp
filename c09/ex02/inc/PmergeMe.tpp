#include "PmergeMe.hpp"

#include <algorithm>
#include <iterator>
#include <cmath>

static std::vector<int> generateJacobsthal(size_t length);
static int approximateBinarySearchComparisons(int N);

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
void	PmergeMe<Container>::PmergeMe::FordJohnsonSort()
{
	//return is length is only 1 and by definition sorted
	if (_container.size() <= 1)
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
	std::vector<std::pair<int, int>> pairs = createPairs();

	//recursively  (merge) sort the pairs larger numbers
	SortPairs(pairs, 0, pairs.size() - 1);
	
	//insertion sort the lower numbers in using the Jacobsthal indexes
	_container = insertionSortList(pairs);

	//insert the trailingnum using binary insertion
	if (hasTrailingNum)
	{
		g_comparison_count += approximateBinarySearchComparisons(_container.size());
		auto it = std::lower_bound(_container.begin(), _container.end(), trailingNum);
		_container.insert(it, trailingNum);
	}
}

template <typename Container>
std::vector<std::pair<int, int>>	PmergeMe<Container>::PmergeMe::createPairs()
{
	std::vector<std::pair<int, int> > list;

	auto item = _container.begin();
	//iterate over the items 
	while (item != _container.end() && std::next(item) != _container.end())
	{
		//set item2 to item+1
		auto item2 = std::next(item);

		//sort the pairs on largest first and add to list
		g_comparison_count++;
		*item > *item2 ? list.push_back(std::make_pair(*item, *item2)) : list.push_back(std::make_pair(*item2, *item));
			
		//set item to item2+1
		item = std::next(item2);
	}

	return list;
}


template <typename Container>
Container PmergeMe<Container>::insertionSortList(std::vector<std::pair<int, int>> sortedPairs)
{
	//create container to return sorted list
	Container returnContainer;

	//create temporary vector with unsorted, smaller numbers
	std::vector<int>	smallerNumbers;

	for (auto pair : sortedPairs)
	{
		//add bigger numbers, sorted
		returnContainer.push_back(pair.first);
		//add smaller number to tempvector
		smallerNumbers.push_back(pair.second);
	}

	//insert first number of smaller numbers into 
	returnContainer.insert(returnContainer.begin(), smallerNumbers[0]);

	//get all the jacobsthal numbers that exist in the length of the list
	std::vector<int> JacobsthalIndexes = generateJacobsthal(smallerNumbers.size());

	// add the final index of the smallerIndex to the jacobstahl to get the last few numbers
	JacobsthalIndexes.push_back(smallerNumbers.size() - 1);

	int	smallerJacob = 0;

	//find and insert the small numbers into the returnContainer using binary search
	for (size_t index = 0; index < JacobsthalIndexes.size(); index++)
	{
		int	biggerJacob = JacobsthalIndexes[index];

		while (biggerJacob > smallerJacob)
		{
			// add approximate comparisons to the global count
			g_comparison_count += approximateBinarySearchComparisons(returnContainer.size());

			//find index and insert current small number
			auto it = std::lower_bound(returnContainer.begin(), returnContainer.end(), smallerNumbers[biggerJacob]);
			returnContainer.insert(it, smallerNumbers[biggerJacob]);
			biggerJacob--;
		}
		smallerJacob = JacobsthalIndexes[index];
	}
	return (returnContainer);
} 

static void merge(std::vector<std::pair<int, int>> &pairs, int left, int mid, int right)
{
	// get the length of both arrays
	int sizeLeft = mid - left + 1;
	
	int sizeRight = right - mid;

	// create temporary arrays
	std::vector<std::pair<int, int>> leftArray(sizeLeft);
	std::vector<std::pair<int, int>> rightArray(sizeRight);

	//copy data into both temp arrays
	for (int i =0; i < sizeLeft; i++)
		leftArray[i] = pairs[left + i];

	for (int j = 0; j < sizeRight; j++)
		rightArray[j] = pairs[mid + 1 + j];

	// merge the temp arrays back into main array
	int i = 0;
	int j = 0;
	int k = left;

	while (i < sizeLeft && j < sizeRight)
	{
		g_comparison_count++;
		if (leftArray[i].first < rightArray[j].first) //sorting here
		{
			pairs[k] = leftArray[i];
			i++;
		}
		else
		{
			pairs[k] = rightArray[j];
			j++;
		}
		k++;
	}

	//merge whatever is left of the arrays back into the main array
	while (i < sizeLeft)
	{
		pairs[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < sizeRight)
	{
		pairs[k] = rightArray[j];
		j++;
		k++;
	}
}


// Recursive merge sort by the first value of the pair
template <typename Container>
void PmergeMe<Container>::SortPairs(std::vector<std::pair<int, int>> &pairs, int left, int right) 
{
	if (left >= right)
		return ;
	

	int mid = left + (right - left) / 2; //find the middle point

	//recursively sort both halves
	SortPairs(pairs, left, mid);
	SortPairs(pairs, mid + 1, right);

	//merge both halves
	merge(pairs, left, mid, right);
}


template <typename Container>
void PmergeMe<Container>::PmergeMe::print()
{
	for (auto item : _container)
		std::cout << item << " ";
	std::cout << std::endl;
}

static size_t	jacobsthal(size_t depth)
{
	if (depth == 0)
		return (0);
	if (depth == 1)
		return (1);
	
	return (jacobsthal(depth -1) + (2 * jacobsthal(depth - 2)));
}

static std::vector<int> generateJacobsthal(size_t length)
{
	std::vector<int>	jacobsthals;

	//set the index to the first index that matters
	size_t	jacobsIndex = 3;

	while (jacobsthal(jacobsIndex) < length)
	{
		jacobsthals.push_back(jacobsthal(jacobsIndex));
		jacobsIndex++;
	}

	return (jacobsthals);
}

static int approximateBinarySearchComparisons(int N)
{
	if (N <= 0)
		return (0);
	return (log2(N + 1));
}