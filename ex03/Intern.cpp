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
    int j = -1;
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    forms[0] = new RobotomyRequestForm(target);
    forms[1] = new PresidentialPardonForm(target);
    forms[2] = new ShrubberyCreationForm(target);
    for (int i = 0; i < 3; i++) {
        if (name != formNames[i])
            delete forms[i];
        else
            j = i;
    }
    if (j == -1) throw Intern::FormNotCreated();
    std::cout << "Intern creates " << name << std::endl;
    return forms[j];
}