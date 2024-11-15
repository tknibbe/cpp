#include "../inc/Span.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

Span::Span(int N) : _maxN(N){
	_numbers.reserve(N);
}

Span::~Span(void){

}
Span::Span(const Span& other){
	*this = other;
	
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
		*this  = other;
	return (*this);
}

void	Span::addNumber(int newNumber){
	
	if (_numbers.size() >= _maxN)
		throw storageLimitExceeded ();
	
	_numbers.push_back(newNumber);

}


int	Span::shortestSpan(){

	if (_numbers.size() <= 1)
		throw noSpanToBeFound();


	//sort the array so the 
	std::sort(_numbers.begin(), _numbers.end());

	// set smallest to max_int to find any span
	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 1; i < _numbers.size(); i++)
	{
		int span = _numbers[i] - _numbers[i - 1];

		//if min span is found, return
		if (span == 0)
			return span;

		// check whether current position is smaller then previous smallest
		if (span < minSpan)
			minSpan = span;
	}

	return (minSpan);
}


int	Span::longestSpan(){

	if (_numbers.size() <= 1)
		throw noSpanToBeFound();

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> minMax;
	
	//find the min and max of the array
	minMax = std::minmax_element(_numbers.begin(), _numbers.end());

	//return the span
	return (*minMax.second - *minMax.first);
}

void Span::print()
{
	std::cout << "PRINTING SPAN:\n\t";
	for (size_t i=0; i < _numbers.size(); i++)
	{
		std::cout << _numbers[i] << " ";
	}
	std::cout << std::endl;
}