#pragma once

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;
	protected:

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array&	operator=(const Array& other);
		T& operator[](std::size_t index);
		const T& operator[](std::size_t index) const;
		unsigned int	size() const;

	class indexTooHighException : public std::exception{
		const char* what() const throw();
	};
};

template <typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& ref);

#include "Array.tpp"