#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { std::cout << "[Bureaucrat] Void constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n), grade(g) {
	std::cout << "[Bureaucrat] Full constructor called" << std::endl;
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	std::cout << "Hi, I'm " << name << " and my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name) {
	std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
	grade = copy.grade;
	std::cout << "Hi, I'm " << name << " and my grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() { std::cout << "[Bureaucrat] destructor" << std::endl; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "[Bureaucrat] Assignation" << std::endl;
	grade = copy.grade;
	return *this;
}

int Bureaucrat::getGrade() const { return grade; }

std::string Bureaucrat::getName() const { return name; }

void Bureaucrat::incrementGrade() {
	if (grade <= 1) throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) throw GradeTooHighException();
	grade++;
}

void Bureaucrat::signForm(Form *f) const {
	try {
		f->beSigned(*this);
		std::cout << name << " signed " << f->getName() << ".";
		} catch (Form::GradeTooLowException &e) {
		std::cout << name << " couldn’t sign " << f->getName() << " : not high-graded enough.";
		}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}