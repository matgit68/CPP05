#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    RobotomyRequestForm();
    std::string target;

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

	void execute(Bureaucrat const &executor) const;
};

#endif