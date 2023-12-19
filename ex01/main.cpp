#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat	b1("Bobby", 11);
	Form		f1("Formulaire 1", 10, 10);

	std::cout << b1 << std::endl;
	b1.signForm(&f1);
	std::cout << f1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.signForm(&f1);
	std::cout << f1 << std::endl;

	return 0;
}