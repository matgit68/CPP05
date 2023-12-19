#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define RESET	 "\033[0m"
# define RED	 "\033[31;1m"
# include <iostream>

class Bureaucrat {
private:
	std::string const name;
	int grade;
	Bureaucrat();
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &copy);

	int getGrade() const;
	std::string getName() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Already at highest grade" RESET; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return RED "Already at lowest grade" RESET; }
	};

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif