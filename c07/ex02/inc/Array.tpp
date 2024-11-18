#include "../inc/Array.hpp"
#include <iostream>
#include <cstring>
#pragma once

template <typename T>
Array<T>::Array(void) : _array(new T[0]()), _size(0){
	// std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) :_array(new T[n]()), _size(n){
	// std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(void){
	// std::cout << "Array destructor called" << std::endl;
	delete [] _array;
}

template <typename T>
Array<T>::Array(const Array& ref) : _array(new T[ref._size]()), _size(ref._size){
	// std::cout << "Array copy constructor called" << std::endl;
	for (unsigned int i=0; i < _size; i++)
	{
		_array[i] = ref._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& ref){
	// std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		delete [] _array;
		_size = ref._size;
		_array = (new T[ref._size]());
		for (unsigned int i=0; i < _size; i++)
			_array[i] = ref._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](std::size_t index){
	if (index >= _size)
		throw	Array<T>::indexTooHighException();
	
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const{
	if (index >= _size)
		throw	Array<T>::indexTooHighException();
	
	return _array[index];
}

template <typename T>
const char * Array<T>::indexTooHighException::what() const throw(){
	return ("Error, Index too high!");
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& ref){
	for (unsigned int i = 0; i < ref.size(); i++){
		os << ref[i] << " ";
	}
	return (os);
}

template <typename T>
unsigned int	Array<T>::size() const{
	return (_size);
}