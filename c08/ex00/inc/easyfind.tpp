#include "easyfind.hpp"

template <typename T>
auto easyfind(T &haystack, int needle) -> decltype(haystack.begin())
{
	auto iter = std::find(haystack.begin(), haystack.end(), needle);

	if (iter == haystack.end())
		throw argumentNotFoundException();

	return (iter);
}

const char * argumentNotFoundException::what() const throw(){
	return ("EXCEPTION: Argument not found");
}