#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { std::cout << "Void constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n), grade(g) {
	std::cout << "Full constructor called" << std::endl;
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	std::cout << "Hi, I'm " << name << " and my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name) {
	grade = copy.grade;
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Incrementing " << name << std::endl;
	if (grade <= 1) throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	std::cout << "Decrementing " << name << std::endl;
	if (grade >= 150) throw GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}