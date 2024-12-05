#pragma once

#include <vector>
#include <list>
#include <iostream>

template <typename Container = std::vector<int> >
class	PmergeMe {

	private:
		Container	_container;

	public :
		PmergeMe(std::vector<std::string> args);
		~PmergeMe() = default;
		PmergeMe(const PmergeMe &other) = delete;
		PmergeMe &operator=(const PmergeMe &other) = default;

		void	sort();
		std::list<std::pair<int, int>>	createAndSortPairs();
		void	print();

};

#include "PmergeMe.tpp"