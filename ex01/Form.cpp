#include "Form.hpp"

Form::Form() : name(""), toSign(0), toExec(0), isSigned(0) {
	std::cout << "[Form] Void constructor called" << std::endl;
}

Form::Form(std::string &n, int &gts, int &gte) : name(n), toSign(gts), toExec(gte), isSigned(0) {
	std::cout << "[Form] Full constructor called" << std::endl;
	if (toSign < 1 || toExec < 1) throw GradeTooHighException();
	if (toSign > 150 || toExec > 150) throw GradeTooLowException();
	std::cout << *this << std::endl;
}

Form::Form(std::string n, int gts, int gte) : name(n), toSign(gts), toExec(gte), isSigned(0) {
	std::cout << "[Form] Full constructor called" << std::endl;
	if (toSign < 1 || toExec < 1) throw GradeTooHighException();
	if (toSign > 150 || toExec > 150) throw GradeTooHighException();
	std::cout << *this << std::endl;
}

Form::Form(Form const &copy) :	name(copy.name), toSign(copy.toSign), toExec(copy.toExec) {
	std::cout << "[Form] Copy constructor called" << std::endl;
	std::cout << *this << std::endl;
}

Form::~Form() { std::cout << "[Form] destructor" << std::endl; }

Form& Form::operator=(const Form &copy) {
	std::cout << "[Form] Assignation" << std::endl;
	isSigned = copy.getIsSigned();
	return *this;
}

std::string Form::getName() const { return (name); }
int Form::getToSign() const { return (toSign); }
int Form::getToExec() const { return (toExec); }
bool Form::getIsSigned() const { return (isSigned); }

void Form::beSigned(const Bureaucrat &b) {
	if (toSign < b.getGrade()) throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &o, const Form &f) {
    o << f.getName() << ", grade required to sign (" << f.getToSign();
	o << "), to execute (" << f.getToExec() << "). Signed : " << f.getIsSigned();
    return o;
}