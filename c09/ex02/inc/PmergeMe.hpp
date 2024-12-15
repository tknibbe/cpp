#pragma once

#include <vector>
#include <list>
#include <iostream>

extern int	g_comparison_count;

template <typename Container = std::vector<int> >
class	PmergeMe {

	private:
		Container	_container;

	public :
		PmergeMe(std::vector<std::string> args);
		~PmergeMe() = default;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = default;

		void								FordJohnsonSort();
		std::vector<std::pair<int, int>>	createPairs();
		void								SortPairs(std::vector<std::pair<int, int>> &list, int left, int right);
		Container							insertionSortList(std::vector<std::pair<int, int>> sortedPairs);
		void								print();

};

#include "PmergeMe.tpp"