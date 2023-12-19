#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	const int toSign;
	const int toExec;
	bool isSigned;
	AForm();

public:
	AForm(std::string &n, int &gts, int &gte);
	AForm(std::string n, int gts, int gte);
	AForm(AForm const &f);
	~AForm();

	AForm &operator=(AForm const &ref);

	std::string getName() const;
	int getToSign() const;
	int getToExec() const;
	bool getIsSigned() const;

	virtual void beSigned(Bureaucrat const &b) = 0;
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Grade too high" RESET; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Grade too low" RESET; }
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &b);

#endif