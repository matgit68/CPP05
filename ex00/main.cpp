#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b1("Bobby", 15);
	Bureaucrat b("First", 2);
	Bureaucrat b2(b1);
	Bureaucrat b3("Last", 149);

	std::cout << b << std::endl;
	try {b.incrementGrade();} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << b << std::endl;
	try {b.incrementGrade();} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	try {b.incrementGrade();} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << b << std::endl;
	std::cout << b3 << std::endl;
	try {b3.decrementGrade();} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << b3 << std::endl;
	try {b3.decrementGrade();} catch(std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << b3 << std::endl;

	try {Bureaucrat b4("Min", -1);} catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try{Bureaucrat b5("Max", 54242);} catch (std::exception &e) {std::cout << e.what() << std::endl;}

	return 0;
}