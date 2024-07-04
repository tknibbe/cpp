#include "../inc/scalarConverter.hpp"
#include <iostream>
#include <limits>


bool isValidChar(std::string& str){
	if (str[0] >= 0 && str[0] <= 127 && str.length() == 1
					&& !(str[0] >= '0' && str[0] <= '9'))
		return (true);
	return (false);
}

bool isValidFloat(const std::string& str) {
	if (str[str.length() - 1] != 'f') //check whether the string ends with an 'f'
		return (false);

	try {
		size_t pos;
		std::stof(str, &pos);

		// Check if the entire string was used to form the float
		return pos == str.size() - 1;
	} catch (std::invalid_argument& e) {
		return false; // Not a valid float
	} catch (std::out_of_range& e) {
		std::cout << "out of range of a float! ";
		return false; // Out of float range
	}
}

bool isValidDouble(const std::string& str) {
	try {
		size_t pos;
		std::stod(str, &pos);

		// Check if the entire string was used to form the double
		return pos == str.size();
	} catch (std::invalid_argument& e) {
		return false; // Not a valid double
	} catch (std::out_of_range& e) {
		std::cout << "out of range for a double! ";
		return false; // Out of double range
	}
}

void	pseudoConvert(std::string &str){
	std::cout << "char: impossible\nint: impossible\n";
	if (str == "nanf" || str == "nan")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f\n";
		std::cout << "double: "<< std::numeric_limits<double>::quiet_NaN() << "\n";
	}
	else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f\n";
		std::cout << "double: "<< std::numeric_limits<double>::infinity() << "\n";
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -" << std::numeric_limits<float>::infinity() << "f\n";
		std::cout << "double: -"<< std::numeric_limits<double>::infinity() << "\n";
	}
}

std::string	charConvert(double num){

	std::string ret;
	// check whether "num" is in the ascii
	if (num >= 0 && num <= 127)
	{
		if(num <= 32)
			ret = "is non-printable";
		else
			ret = static_cast<char> (num);
	}
	else
		ret = "impossible";
	return (ret);
}

std::string	intConvert(double num){
	std::string ret;
	
	// Check for out-of-range errors
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		ret = "impossible";
	else
		ret = std::to_string(static_cast<int> (num));
	return (ret);
}

std::string	floatConvert(double num){
	std::string ret;
	
	// Check for out-of-range errors
	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::lowest())
		ret = "impossible";
	else
		ret = std::to_string(num)+"f";
	return (ret);
}

std::string	doubleConvert(double num){
	std::string ret;
	
	// Check for out-of-range errors
	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::lowest())
		ret = "impossible";
	else
		ret = std::to_string(num);
	
	return (ret);

}

void scalarConverter::convert(std::string &input){
	// Check for special floating-point values (e.g., nan, inf) and handle them
	if	(input ==	"nanf"	||
		input ==	"nan"	||
		input ==	"inf"	||
		input ==	"inff"	||
		input ==	"-inf"	||
		input ==	"-inff"	||
		input ==	"+inf"	||
		input ==	"+inff")
		return pseudoConvert(input);

	// Check if the input is a valid double or float
	else if(isValidDouble(input) || isValidFloat(input)) //only need to know 
	{
		double	num = std::stod(input); //convert string to double

		// Convert and print the value as different scalar types
		std::cout << "char: " << charConvert(num) << "\n";
		std::cout << "int: " << intConvert(num) << "\n";
		std::cout << "float: " << floatConvert(num) << "\n";
		std::cout << "double: " << doubleConvert(num) << "\n";
	}

	// Check if the input is a valid single character
	else if (isValidChar(input))
	{
		// Convert and print the value as different scalar types
		std::cout << "char: " << charConvert(static_cast<double> (input[0])) << "\n";
		std::cout << "int: " << static_cast<int>(input[0]) << "\n";
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f\n";
		std::cout << "double: " << static_cast<double>(input[0]) << ".0\n";	
	}

	// If the input is invalid, print an error message
	else
		std::cout << "Invalid input. please retry\n";
}