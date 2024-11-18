// #include <iostream>
// #include "../inc/Array.hpp"

// #define BLUE "\033[0;34m"
// #define WHITE "\033[0;37m"

// int main( void ) {

// 	{
// 		Array<double>	test;
// 		std::cout << BLUE << "illegal instructions on empty array:\n\n" << WHITE;
// 		try {
// 			std::cout << test[0];
// 		}
// 		catch (std::exception &e){
// 			std::cout << e.what() << "\n\n";
// 		}
// 		try {
// 			test[0] = 1;
// 		}
// 		catch (std::exception &e){
// 			std::cout << e.what() << "\n\n";
// 		}
// 	}


// 	std::cout << BLUE << "\n\nillegal instructons on initialized array:\n" << WHITE;
// 	{
// 		Array<int>	array(10);
// 		for(int i=0; i<10; i++){
// 			array[i] = i * 5;
// 		}
// 		try {
// 			std::cout << array[10];
// 		}
// 		catch (std::exception &e){
// 			std::cout << e.what() << "\n\n";
// 		}
// 		try {
// 			array[10] = 99;
// 		}
// 		catch (std::exception &e){
// 			std::cout << e.what() << "\n\n";
// 		}
// 	}


// 	std::cout << BLUE << "\n\ninstructons on uninitialized array:\n" << WHITE;
// 	{
// 		Array<int>	array(10);
// 		try {
// 			std::cout << array << "\n";
// 		}
// 		catch (std::exception &e){
// 			std::cout << e.what() << "\n\n";
// 		}
// 	}

// 	{
// 		std::cout << BLUE << "\n\ninstructons on initialized array:\n" << WHITE;
// 		Array<int>	array(10);
// 		for(int i=0; i<10; i++){
// 			array[i] = i * 5;
// 		}
// 		std::cout << "array:\n" << array << "\n";
// 	}
// 	{
// 	std::cout << BLUE << "\n\ninstructons on string array:\n" << WHITE;
// 		Array<std::string>	str(5);
// 		std::string			text("test");


// 		std::cout << "unitinialized:\n" << str << "\n";


// 		for (int i=0; i<5;i++)
// 		{
// 			str[i] = text + std::to_string(i);
// 		}
// 		std::cout << "initialized:\n" << str << "\n";
// 	}

// 	std::cout << BLUE << "\nreassigning array to test leaks:\n" << WHITE;
// 	{
// 		Array<int> int1(5);
// 		Array<int> int2(2);
// 		for (int i=0; i<5;i++)
// 		{
// 			int1[i] = i;
// 		}
// 		std::cout << int1<< "\n";
// 		int1 = int2;
// 		std::cout << int1 <<"\n";
// 	}

// 	Array<std::string> str1(5);
// 	std::cout << BLUE << "\nreassigning array to test leaks:\n" << WHITE;
// 	{
// 		Array<std::string> str2(2);
// 		std::string			text("test");

// 		str2[0] = "New string!";
// 		str2[1] = "another new string!";
// 		for (int i=0; i<5;i++)
// 		{
// 			str1[i] = text + std::to_string(i); 
// 		}
		
// 		std::cout << "\nstr1 before reassigning =\n" << str1 << "\n";
// 		str1 = str2;
// 	}
// 	//str2 will be destructed here so if the value is in str1 it sure is a deep copy
// 	std::cout << "\nstr1 after reassigning =\n" << str1 << "\n\n";
// 	return 0;
// }
#include <iostream>
#include "../inc/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}