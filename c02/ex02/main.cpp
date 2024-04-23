#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	//test comparison operators
	//	>,< >=,<=,==,!=
	std::cout << "\n\n----testing comparisons---\n\n";
	Fixed	comp1(3);
	Fixed	comp2(10);
	Fixed	comp3(10);

	std::string ans;

	ans = comp1 > comp2 ? "1: True\n" : "1: False\n";
	std::cout << ans;

	ans = comp1 < comp2 ? "2: True\n" : "2: False\n";
	std::cout << ans;

	ans = comp1 <= comp2 ? "3: True\n" : "3: False\n";
	std::cout << ans;

	ans = comp3 <= comp2 ? "4: True\n" : "4: False\n";
	std::cout << ans;
	
	ans = comp3 == comp2 ? "5: True\n" : "5: False\n";
	std::cout << ans;

	ans = comp3 != comp2 ? "6: True\n" : "6: False\n\n\n";
	std::cout << ans;

	// test arithmic operators //test with floats!
	// 	+,-,*,/
	Fixed	arit(12.3f);
	Fixed	arit2(45.6f);
	Fixed	arit3(30.2f);
	Fixed	test;

	std::cout << "----testing additions---\n\n";
	test = arit + arit2 + arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "+" << '\n';
	std::cout << arit2 << "+" << '\n';
	std::cout << arit3 << "+" << "\n\n\n";


	std::cout << "----testing subtractions---\n\n";
	test = arit - arit2 - arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "-" << '\n';
	std::cout << arit2 << "-" << '\n';
	std::cout << arit3 << "\n\n\n";

	std::cout << "----testing multiplications---\n\n";
	test = arit * arit2 * arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "*" << '\n';
	std::cout << arit2 << "*" << '\n';
	std::cout << arit3 << "\n\n\n";

	arit = Fixed(1000.5f);
	arit2 = Fixed(10.6f);
	arit3 = Fixed(2);
	std::cout << "----testing devisions---\n\n";
	test = arit / arit2 / arit3;
	std::cout << "test = " << test << '\n';
	std::cout << arit << "/" << '\n';
	std::cout << arit2 << "/" << '\n';
	std::cout << arit3 << "\n\n\n";

	//test in/decrement operators
	std::cout << "----testing in/decrement---\n\n";
	Fixed crement;

	std::cout << crement << '\n';
	std::cout << ++crement << '\n';
	std::cout << crement << '\n';
	std::cout << crement++ << '\n';
	std::cout << crement << "\n\n";

	std::cout << crement << '\n';
	std::cout << --crement << '\n';
	std::cout << crement << '\n';
	std::cout << crement-- << '\n';
	std::cout << crement << "\n\n\n";


	// test min/max()
	std::cout << "----testing min/max---\n\n";
	std::cout << "1: " << Fixed::min(arit, arit2) << "\n";
	std::cout << "2: " << Fixed::min(arit2, arit3) << "\n";
	std::cout << "3: " << Fixed::max(arit, arit2) << "\n";
	std::cout << "4: " << Fixed::max(arit2, arit3) << "\n\n\n";

	return 0;
}