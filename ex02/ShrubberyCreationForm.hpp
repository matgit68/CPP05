#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>
# include <string>

class ShrubberyCreationForm : public AForm {
private:
    ShrubberyCreationForm();
    std::string target;

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

	void execute(Bureaucrat const &executor) const;

};

#endif
