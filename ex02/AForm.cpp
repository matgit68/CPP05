#include "AForm.hpp"

AForm::AForm() : name(""), toSign(0), toExec(0), isSigned(0) {
	std::cout << "[AForm] Void constructor called" << std::endl;
}

AForm::AForm(std::string &n, int &gts, int &gte) : name(n), toSign(gts), toExec(gte), isSigned(0) {
	std::cout << "[AForm] Full constructor called" << std::endl;
	if (toSign < 1 || toExec < 1) throw GradeTooHighException();
	if (toSign > 150 || toExec > 150) throw GradeTooLowException();
	std::cout << *this << std::endl;
}

AForm::AForm(std::string n, int gts, int gte) : name(n), toSign(gts), toExec(gte), isSigned(0) {
	std::cout << "[AForm] Full constructor called" << std::endl;
	if (toSign < 1 || toExec < 1) throw GradeTooHighException();
	if (toSign > 150 || toExec > 150) throw GradeTooHighException();
	std::cout << *this << std::endl;
}

AForm::AForm(AForm const &copy) : name(copy.name), toSign(copy.toSign), toExec(copy.toExec) {
	std::cout << "[AForm] Copy constructor called" << std::endl;
	std::cout << *this << std::endl;
}

AForm::~AForm() { std::cout << "[AForm] destructor" << std::endl; }

AForm& AForm::operator=(const AForm &copy) {
	std::cout << "[AForm] Assignation" << std::endl;
	isSigned = copy.getIsSigned();
	return *this;
}

std::string AForm::getName() const { return (name); }
int AForm::getToSign() const { return (toSign); }
int AForm::getToExec() const { return (toExec); }
bool AForm::getIsSigned() const { return (isSigned); }
void AForm::setSigned(bool s) { isSigned = s; }

void AForm::beSigned(const Bureaucrat &b) {
	if (isSigned) {
		std::cout << "Form already signed" << std::endl;
		return ;
	}
	if (toSign < b.getGrade()) throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &o, const AForm &f) {
    o << f.getName() << ", grade required to sign (" << f.getToSign();
	o << "), to execute (" << f.getToExec() << "). Signed : " << std::boolalpha << f.getIsSigned();
    return o;
}