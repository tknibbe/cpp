#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void){
	Bureaucrat	Larry("Larry", 10);
	Bureaucrat	Barry("Barry", 150);

	ShrubberyCr                    _
                  _(_)_                          wWWWw   _
      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
     @@()@@ wWWWw  (_)|    (___)   _(_)_  @@()@@   Y  (_)@(_)
      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   ||/   (_)|
       /      Y       ||    ||/    /(_)    ||      |/      |
    | |     | |/       | / | | /  ||/       |/    ||      ||/
    |||//   |||///  ||||//||||/// ||///  ||||//  |||//  ||||// 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    _
                  _(_)_                          wWWWw   _
      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
     @@()@@ wWWWw  (_)|    (___)   _(_)_  @@()@@   Y  (_)@(_)
      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   ||/   (_)|
       /      Y       ||    ||/    /(_)    ||      |/      |
    | |     | |/       | / | | /  ||/       |/    ||      ||/
    |||//   |||///  ||||//||||/// ||///  ||||//  |||//  ||||// 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
eationForm	shrub("new");

	std::cout << "\n-----signing and executing shrub form with Larry----\n";
	Larry.signForm(shrub);
	try {
		shrub.execute(Larry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	std::cout << "\n----trying to execute with Barry----\n";
	try {
		shrub.execute(Barry);
	}
	catch(std::exception &e){
		std::cout << "exception caught! " << e.what() << "\n";
	}
	// std::cout << shrub <<"\n";
}