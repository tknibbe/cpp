#pragma once
#include <algorithm>

template <typename T>
auto easyfind(T &haystack, int needle) -> decltype(haystack.begin());


class argumentNotFoundException : public std::exception
{
	const char* what() const throw();
};

#include "easyfind.tpp"