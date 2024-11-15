#include <iostream>
#include "../inc/Span.hpp"

#include <bits/stdc++.h>
#include <list>

int main( void ) {

	std::cout << "Pdf test:\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	//test with max int?

	//testing Span limits
	std::cout << "Testing construction of int_max\n";
		{Span sp2(std::numeric_limits<int>::max());}
	
	
	std::cout << "\nTesting manual adding of 500 numbers (expected output: 499 and 1):\n";
	Span test500 (500);
	for (int i=0;i<500;i++)
		test500.addNumber(i);
	std::cout << "\tOutput longest : " << test500.longestSpan() << "\n";
	std::cout << "\tOutput shortest: " << test500.shortestSpan() << "\n";

	std::cout << "\nTesting out of range addition:\n\t";
	Span testRange(20);
	try {
		for (int i=0;i<=20;i++)
			testRange.addNumber(i);
	}
	catch (std::exception &e){
		std::cout << e.what() << "\n";
	}

	std::cout << "Testing calculations on non-existing spans\n";
	try {
		Span zero (0);
		std::cout << "\tspan from empty Span: " << zero.longestSpan() << "\n";
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try {
		Span one (50);
		one.addNumber(24);
		std::cout << "\tspan from Span with only one member :  " << one.longestSpan() << "\n";
	}
	catch (std::exception &e){
		std::cout << e.what();
	}



	std::cout << "\ntesting iteration addition to the Span\n";
	std::vector <int> bigOne;
	for (size_t i=0; i < 100000; i++)
		bigOne.push_back(i);

	Span bigOneSpan (100000);
	try {
		bigOneSpan.addNumber(bigOne.begin(), bigOne.end());
		// bigOneSpan.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "Testing adding non-begin and end pointers into Span\n\t";
	Span smallItertest(5);
	try {
		smallItertest.addNumber(bigOne.begin() + 5, bigOne.begin ()+10);
		smallItertest.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "Testing adding a range of items from  a list\n\t";
	std::list<int> testList{12, 10, 5, 25, 40, 200, 74, 1, 99, 2};
	Span	testListSpan(10);
	try{
		testListSpan.addNumber(testList.begin(), testList.end());
		testListSpan.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}


	std::cout << "Testing adding a range of items from  a deque\n\t";
	std::deque<int> testDeque{12, 10, 5, 25, 40, 200, 74, 1, 99, 2};
	Span	testDequeSpan(10);
	try{
		testDequeSpan.addNumber(testDeque.begin(), testDeque.end());
		testDequeSpan.print();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return 0;
}
