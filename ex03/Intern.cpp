#include "Intern.hpp"

Intern::Intern() { std::cout << "[Intern] Void constructor called" << std::endl;
}

Intern::Intern(Intern const &copy) {
    std::cout << "[Intern] Copy constructor called" << std::endl;
    *this = copy;
}

Intern::~Intern() { std::cout << "[Intern] Destructor called" << std::endl; }

Intern &Intern::operator=(Intern const &copy) {
    std::cout << "[Intern] Assignation" << std::endl;
    (void) copy;
    return *this;
}

AForm *Intern::makeForm( std::string name, std::string target ) {
    int i = 0;
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm *clone;
    forms[0] = new RobotomyRequestForm(target);
    forms[1] = new PresidentialPardonForm(target);
    forms[2] = new ShrubberyCreationForm(target);
    for (; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            clone = (*forms)[i].clone();
        }
        delete forms[i];
    }
    if (i > 3) throw Intern::FormNotCreated();
    else
        return clone;
}