#pragma once
#include <iostream>

#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"


template <typename T>
using func = void (*) (T&);

template <typename T>
void iter(T* arr, size_t len, func<T> f){
	for (size_t i=0;i<len;i++){
		f(arr[i]);
	}
}

template <typename T>
void print(T item){
	std::cout << item << " ";
}

template <typename T>
void	plusOne(T item){
	++item;
}

template <typename T>
void	printTestForMain(T* arr, int len){

	std::cout << BLUE << "before:\n" << WHITE;
	::iter(arr, len, ::print);
	::iter(arr, len, ::plusOne);
	std::cout << BLUE << "\nafter adding one:\n" << WHITE;
	::iter(arr, len, ::print);
}