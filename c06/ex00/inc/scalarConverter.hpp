#pragma once
#include <string>

class scalarConverter {
	private:
		scalarConverter() = delete;
		~scalarConverter() = delete;
		scalarConverter(const scalarConverter& other) = delete;
		scalarConverter&	operator=(const scalarConverter& other) = delete;

	protected:

	public:
		static void	convert(std::string &ref);
};
