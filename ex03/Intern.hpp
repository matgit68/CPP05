#ifndef INTERN_HPP
# define INTERN_HPP
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

private:
    AForm *forms[3];

public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();

    Intern& operator=(Intern const &copy);

    AForm *makeForm(std::string name, std::string target);

	class FormNotCreated : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "No form like this" RESET; }
	};
};

#endif