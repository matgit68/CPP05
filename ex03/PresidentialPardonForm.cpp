#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
    target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", 25, 5) {
    target = t;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) :  AForm(copy) {
    target = copy.target;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "[PPF Destructed]" << std::endl; }

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &f) {
    setSigned(f.getIsSigned());
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec()) throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " execute " << this->getName() << " : " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm* PresidentialPardonForm::clone() const {
    return new PresidentialPardonForm(target);
}