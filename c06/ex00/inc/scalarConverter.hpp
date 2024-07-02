#pragma once
#include <string>

class scalarConverter {
	private:
		scalarConverter();
		~scalarConverter();
		scalarConverter(const scalarConverter& other);
		scalarConverter&	operator=(const scalarConverter& other);

	protected:

	public:
		static void	convert(std::string &ref);
};
