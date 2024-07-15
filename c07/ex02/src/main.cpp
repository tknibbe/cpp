#include <iostream>
#include "../inc/Array.hpp"

int main( void ) {

	{
		Array<double>	test;
		std::cout << "illegal instructions on empty array:\n\n";
		try {
			std::cout << test[0];
		}
		catch (std::exception &e){
			std::cout << e.what() << "\n\n";
		}
		try {
			test[0] = 1;
		}
		catch (std::exception &e){
			std::cout << e.what() << "\n\n";
		}
	}


	std::cout << "\n\nillegal instructons on initialized array:\n";
	{
		Array<int>	array(10);
		for(int i=0; i<10; i++){
			array[i] = i * 5;
		}
		try {
			std::cout << array[10];
		}
		catch (std::exception &e){
			std::cout << e.what() << "\n\n";
		}
		try {
			array[10] = 99;
		}
		catch (std::exception &e){
			std::cout << e.what() << "\n\n";
		}
	}


	std::cout << "\n\ninstructons on uninitialized array:\n";
	{
		Array<int>	array(10);
		try {
			std::cout << array << "\n";
		}
		catch (std::exception &e){
			std::cout << e.what() << "\n\n";
		}
	}

	{
		std::cout << "\n\ninstructons on initialized array:\n";
		Array<int>	array(10);
		for(int i=0; i<10; i++){
			array[i] = i * 5;
		}
		std::cout << "array:\n" << array << "\n";
	}
	{
	std::cout << "\n\ninstructons on string array:\n";
		Array<std::string>	str(5);
		std::string			text("test");


		std::cout << "unitinialized:\n" << str << "\n";


		for (int i=0; i<5;i++)
		{
			str[i] = text + std::to_string(i);
		}
		std::cout << "initialized:\n" << str << "\n";
	}

	std::cout << "\nreassigning array to test leaks:\n";
	{
		Array<int> int1(5);
		Array<int> int2(2);
		for (int i=0; i<5;i++)
		{
			int1[i] = i;
		}
		std::cout << int1<< "\n";
		int1 = int2;
		std::cout << int1 <<"\n";
	}

	Array<std::string> str1(5);
	std::cout << "\nreassigning array to test leaks:\n";
	{
		Array<std::string> str2(2);
		std::string			text("test");

		str2[0] = "{placeholder text here}";
		for (int i=0; i<5;i++)
		{
			str1[i] = text + std::to_string(i); 
		}
		
		std::cout << "str1 mid-way = " << str1 << "\n";
		str1 = str2;
	}
	//str2 will be destructed here so if the value is in str1 it sure is a deep copy
	std::cout << "str1 final = " << str1 << "\n\n";
	return 0;
}
