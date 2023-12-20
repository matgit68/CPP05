#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string t) : AForm("RobotomyRequestForm", 72, 45) {
    target = t;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :  AForm(copy) {
    target = copy.target;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "[RRF Destructed]" << std::endl; }

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &f) {
    setSigned(f.getIsSigned());
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec()) throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " execute " << this->getName() << " :  *BZZZZZZT* *KRANG !* ";
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed and " << this->target << " is safe" << std::endl;
}