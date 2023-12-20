#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat	bobby("Bobby", 26);
	Bureaucrat	jimmy("Jimmy", 6);
	Intern someRandomIntern;
	AForm* rrf;

	try {
		rrf = someRandomIntern.makeForm("kebab request", "me");
	} catch(std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	} catch(std::exception &e) { std::cout << e.what() << std::endl; }
	try {jimmy.executeForm(*rrf);} catch(std::exception &e) { std::cout << e.what(); }
	try {bobby.signForm(rrf);} catch(std::exception &e) { std::cout << e.what(); }
	try {jimmy.executeForm(*rrf);} catch(std::exception &e) { std::cout << e.what(); }
	delete rrf;
	return 0;
}