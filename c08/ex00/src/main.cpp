#include <iostream>
#include "../inc/easyfind.hpp"
#include <array>
#include <vector>
#include <list>
#include <stack>


int main( void ) {

	std::array<int, 200> intArray;

	for (int i=0;i<200;i++)
		intArray[i] = i;

	try {
		std::cout << "SHOULD RETURN intArray\n";
		std::cout << "\tRESULT intArray: " << *easyfind(intArray, 68) << "\n";
		std::cout << "\tRESULT intArray: " << *easyfind(intArray, 25) << "\n";
		std::cout << "\tRESULT intArray: " << *easyfind(intArray, 0) << "\n";
		std::cout << "\tRESULT intArray: " << *easyfind(intArray, 199) << "\n";
		std::cout << "\nSHOULD ERROR intArray\n\t";
		easyfind(intArray, -1);

	}
	catch (std::exception &e){
		std::cout << e.what() << "\n\n";
	}


	std::vector<int> intVector;
	for (int i=0;i<200;i++)
		intVector.push_back(i);

	try {
		std::cout << "\nSHOULD RETURN intVector\n";
		std::cout << "\tRESULT intVector: " << *easyfind(intVector, 68) << "\n";
		std::cout << "\tRESULT intVector: " << *easyfind(intVector, 25) << "\n";
		std::cout << "\tRESULT intVector: " << *easyfind(intVector, 0) << "\n";
		std::cout << "\tRESULT intVector: " << *easyfind(intVector, 199) << "\n";
		std::cout << "\nSHOULD ERROR intVector\n\t";
		easyfind(intVector, -1);

	}
	catch (std::exception &e){
		std::cout << e.what() << "\n\n";
	}

	std::string justString = "Hey there\n";

	try {
		std::cout << "\nSHOULD RETURN justString\n";
		std::cout << "\tRESULT justString: " << *easyfind(justString, 'r') << "\n";
		std::cout << "\tRESULT justString: " << *easyfind(justString, 't') << "\n";
		std::cout << "\tRESULT justString: " << *easyfind(justString, 'H') << "\n";
		std::cout << "\nSHOULD ERROR justString\n\t";
		easyfind(justString, 'p');

	}
	catch (std::exception &e){
		std::cout << e.what() << "\n\n";
	}

	std::list<int> intList;
	for (int i=0;i<200;i++)
		intList.push_back(i);

	try {
		std::cout << "\nSHOULD RETURN intList\n";
		std::cout << "\tRESULT intList: " << *easyfind(intList, 68) << "\n";
		std::cout << "\tRESULT intList: " << *easyfind(intList, 25) << "\n";
		std::cout << "\tRESULT intList: " << *easyfind(intList, 0) << "\n";
		std::cout << "\tRESULT intList: " << *easyfind(intList, 199) << "\n";
		std::cout << "\nSHOULD ERROR intList\n\t";
		easyfind(intList, -1);

	}
	catch (std::exception &e){
		std::cout << e.what() << "\n\n";
	}


	return 0;
}
