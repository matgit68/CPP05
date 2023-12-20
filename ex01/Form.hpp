#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string name;
	const int toSign;
	const int toExec;
	bool isSigned;
	Form();

public:
	Form(std::string &n, int &gts, int &gte);
	Form(std::string n, int gts, int gte);
	Form(Form const &f);
	~Form();

	Form &operator=(Form const &ref);

	std::string getName() const;
	int getToSign() const;
	int getToExec() const;
	bool getIsSigned() const;

	void beSigned(const Bureaucrat &b);


	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Grade too high" RESET; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Grade too low" RESET; }
	};
};

std::ostream &operator<<(std::ostream &o, const Form &b);

#endif