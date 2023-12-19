#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { std::cout << "Void constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n) {
	std::cout << "Full constructor called" << std::endl;
	grade = g;
	try {
		if (grade < 1) throw GradeTooHighException();
	}
	catch(GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		grade = 1;
	}
	try {
		if (grade > 150) throw GradeTooLowException();
	}
	catch(GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		grade = 150;
	}
	std::cout << "Hi, I'm " << name << " and my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name) {
	std::cout << "Copy constructor called" << std::endl;
	grade = copy.grade;
	std::cout << "Hi, I'm " << name << " and my grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor" << std::endl; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Assignation" << std::endl;
	grade = copy.grade;
	return *this;
}

int Bureaucrat::getGrade() const { return grade; }

std::string Bureaucrat::getName() const { return name; }

void Bureaucrat::incrementGrade() {
	try	{
		grade--;
		if (grade <= 0) throw GradeTooHighException();
	}
	catch(GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		grade = 1;
	}
}

void Bureaucrat::decrementGrade() {
	try	{
		grade++;
		if (grade >= 151) throw GradeTooHighException();
	}
	catch(GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		grade = 150;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}