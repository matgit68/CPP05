#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat	president("Prez", 1);
	Bureaucrat	bobby("Bobby", 26);
	Bureaucrat	jimmy("Jimmy", 6);
	AForm*		f1 = new PresidentialPardonForm("Barabbas");
	AForm*		f2 = new RobotomyRequestForm("Bender");
	AForm*		f3 = new ShrubberyCreationForm("Forest");

	try {president.executeForm(*f1);} catch(std::exception &e) { std::cout << e.what(); }
	std::cout << bobby << std::endl;
	try {bobby.signForm(f1);} catch(std::exception &e) { std::cout << e.what(); }
	std::cout << *f1 << std::endl;
	try {bobby.incrementGrade();} catch(std::exception &e) { std::cout << e.what(); }
	std::cout << bobby << std::endl;
	try {bobby.signForm(f1);} catch(std::exception &e) { std::cout << e.what(); }
	std::cout << *f1 << std::endl;
	try {jimmy.executeForm(*f1);} catch(std::exception &e) { std::cout << e.what(); }
	try {jimmy.incrementGrade();} catch(std::exception &e) { std::cout << e.what(); }
	try {jimmy.executeForm(*f1);} catch(std::exception &e) { std::cout << e.what(); }

	try {jimmy.executeForm(*f2);} catch(std::exception &e) { std::cout << e.what(); }
	try {bobby.signForm(f2);} catch(std::exception &e) { std::cout << e.what(); }
	try {jimmy.executeForm(*f2);} catch(std::exception &e) { std::cout << e.what(); }

	try {jimmy.executeForm(*f3);} catch(std::exception &e) { std::cout << e.what(); }
	try {bobby.signForm(f3);} catch(std::exception &e) { std::cout << e.what(); }
	try {jimmy.executeForm(*f3);} catch(std::exception &e) { std::cout << e.what(); }

	delete f1;
	delete f2;
	delete f3;
	return 0;
}