#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// // std::cout << Fixed::max( a, b ) << std::endl;


	// Fixed max_printable(8388607);

	// //test comparison operators
	// //	>,< >=,<=,==,!=
	// Fixed	comp1(3);
	// Fixed	comp2(10);
	// Fixed	comp3(10);

	// if (comp1 > comp2)
	// 	std::cout << "1: True\n";
	// else
	// 	std::cout << "1: False\n";

	// if (comp1 < comp2)
	// 	std::cout << "2: True\n";
	// else
	// 	std::cout << "2: False\n";

	// if (comp3 <= comp2)
	// 	std::cout << "3: True\n";
	// else
	// 	std::cout << "3: False\n";

	// if (comp3 <= comp2)
	// 	std::cout << "4: True\n";
	// else
	// 	std::cout << "4: False\n";
	
	// if (comp3 == comp2)
	// 	std::cout << "5: True\n";
	// else
	// 	std::cout << "5: False\n";
	
	// if (comp3 != comp2)
	// 	std::cout << "6: True\n";
	// else
	// 	std::cout << "6: False\n";
	

	// test arithmic operators //test with floats!
	// 	+,-,*,/
	Fixed	arit(12.3f);
	Fixed	arit2(45.6f);
	Fixed	arit3(300);
	Fixed	test;

	// std::cout << "----testing additions---\n\n";
	// test = arit + arit2 + arit3;
	// std::cout << "test = " << test << '\n';
	// std::cout << arit << "+" << '\n';
	// std::cout << arit2 << "+" << '\n';
	// std::cout << arit3 << "+" << "\n\n\n";


	// std::cout << "----testing subtractions---\n\n";
	// test = arit - arit2 - arit3;
	// std::cout << "test = " << test << '\n';
	// std::cout << arit << "-" << '\n';
	// std::cout << arit2 << "-" << '\n';
	// std::cout << arit3 << "\n\n\n";

	std::cout << "----testing multiplications---\n\n";
	test = arit * arit2;// * arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "*" << '\n';
	std::cout << arit2 << "*" << '\n';
	std::cout << arit3 << "\n\n\n";


	std::cout << "----testing devisions---\n\n";
	test = arit / arit2 / arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "/" << '\n';
	std::cout << arit2 << "/" << '\n';
	std::cout << arit3 << "\n\n\n";

	//test in/decrement operators
	// Fixed crement;

	// std::cout << crement << '\n';
	// std::cout << ++crement << '\n';
	// std::cout << crement << '\n';
	// std::cout << crement++ << '\n';
	// std::cout << crement << "\n\n";

	// std::cout << crement << '\n';
	// std::cout << --crement << '\n';
	// std::cout << crement << '\n';
	// std::cout << crement-- << '\n';
	// std::cout << crement << '\n';


	return 0;
}