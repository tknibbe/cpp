#include <iostream>
#include "../inc/iter.hpp"


int main( void ) {


	int testInt[10];
	for (int i=0;i<10;i++){
		testInt[i] = 10 - i;
	}
	std::cout << "---int array---\n";
	::printTestForMain(testInt, 10);

	double testDouble[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8,8, 9.9};
	std::cout << "\n\n---Double arrar---\n";
	::printTestForMain(testDouble, 10);

	char testChar[5] = {'a', 'b', 'C', 'Z', '~'};
	std::cout << "\n\n---Char arrar---\n";
	::printTestForMain(testChar, 5);
	std::cout << "\n";


	//no nulltesting available for iter() since it doesnt compile
	//when trying to compare nullptr_t against a T* or function ptr
	return 0;
}
