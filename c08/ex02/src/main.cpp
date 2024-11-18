#include <iostream>
#include "../inc/MutantStack.hpp"
#include <vector>

int main()
{
	std::cout << "INSTRUCTIONS FROM CPP08 PDF ON STACK\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << mstack.top();
		mstack.pop();
		std::cout << " " << mstack.size() << "\t";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << "\n";
		std::stack<int> s(mstack);
	}

	std::cout << "SAME INSTRUCTIONS ON A VECTOR:\n" ;
	{
		std::vector<int> vec;

		vec.push_back(5);
		vec.push_back(17);
		std::cout << "\t" << vec.back();
		vec.pop_back();
		std::cout << " " << vec.size() << "\t";
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(737);
		vec.push_back(0);
		std::vector<int>::iterator itV = vec.begin();
		std::vector<int>::iterator itVe = vec.end();

		++itV;
		--itV;
		while (itV != itVe)
		{
			std::cout << " " << *itV;
			++itV;
		}
		std::cout << "\n";
	}

	std::cout << "INSTANCIATE MUTANTSTACK WITH VECTOR\n";
	{
		//instanciate other containers in the stack
		MutantStack<int, std::vector<int>> MutantVec;

		MutantVec.push(5);
		MutantVec.push(17);
		std::cout << "\t" << MutantVec.top();
		MutantVec.pop();
		std::cout << " " << MutantVec.size() << "\t";
		MutantVec.push(3);
		MutantVec.push(5);
		MutantVec.push(737);
		//[...]
		MutantVec.push(0);
		MutantStack<int, std::vector<int>>::iterator it = MutantVec.begin();
		MutantStack<int, std::vector<int>>::iterator ite = MutantVec.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << "\n";
	}


	std::cout << "SAME AS FIRST BUT THEN WITH A REVERSE_ITERATOR\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << mstack.top();
		mstack.pop();
		std::cout << " " << mstack.size() << "\t";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << "\n";

	}
	std::cout << "SAME AS FIRST BUT WITH CONST ITERATORS\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << mstack.top();
		mstack.pop();
		std::cout << " " << mstack.size() << "\t";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.cbegin();
		MutantStack<int>::const_iterator ite = mstack.cend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << "\n";
		std::stack<int> s(mstack);
	}
	std::cout << "SAME AS FIRST BUT WITH CONST REVERSE ITERATORS\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << mstack.top();
		mstack.pop();
		std::cout << " " << mstack.size() << "\t";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::const_reverse_iterator it = mstack.crbegin();
		MutantStack<int>::const_reverse_iterator ite = mstack.crend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " " << *it;
			++it;
		}
		std::cout << "\n";
		std::stack<int> s(mstack);
	}
	return 0;
}

//test with vector and other containers