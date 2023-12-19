#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b1("Bobby", 15);
	Bureaucrat b("First", 2);
	Bureaucrat b2(b1);
	Bureaucrat b3("Last", 149);

	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	b.incrementGrade();
	b.incrementGrade();
	std::cout << b << std::endl;
	std::cout << b3 << std::endl;
	b3.decrementGrade();
	std::cout << b3 << std::endl;
	b3.decrementGrade();
	std::cout << b3 << std::endl;

	try {Bureaucrat b4("Min", -1);} catch (Bureaucrat::GradeTooHighException &e) {}
	try{Bureaucrat b5("Max", 54242);} catch (Bureaucrat::GradeTooLowException &e) {}

	return 0;
}