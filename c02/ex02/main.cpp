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
	// std::cout << Fixed::max( a, b ) << std::endl;


	Fixed testje(8388607);
	std::cout << "hey Jan, " << testje << '\n';

	//test comparison operators
	//	>,< >=,<=,==,!=
	// Fixed	comp1(3);
	// Fixed	comp2(10);

	//test arithmic operators //test with floats!
	//	+,-,*,/
	Fixed	arit(12.3f);
	Fixed	arit2(45.6f);
	Fixed	arit3(300);

	// std::cout << "----testing additions---\n\n";
	Fixed test = arit + arit2 + arit3;
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
	std::cout << "THIS SHIT IS BROKEN <3\n\n\n\n";
	std::cout << "MAIN: arit = " << arit << " arit2 = " << arit2 << '\n';
	test = arit * arit2;// * arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "*" << '\n';
	std::cout << arit2 << "*" << '\n';
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