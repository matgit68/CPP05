#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
    target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137) {
    target = t;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) :  AForm(copy) {
    target = copy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "[SCF Destructed]" << std::endl; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &f) {
    setSigned(f.getIsSigned());
    return *this;
}

ShrubberyCreationForm* ShrubberyCreationForm::clone() const {
    return new ShrubberyCreationForm(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec()) throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " execute " << this->getName() << " : ";
    try {
        std::ofstream out;
        std::string outfile = target + "_shrubbery";
	    out.open(outfile.c_str());
        if (out.fail()) throw std::ios_base::failure("Erreur d'ouverture du fichier en écriture");
        out << "               ,@@@@@@@,\n";
        out << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
        out << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
        out << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
        out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
        out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
        out << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
        out << "       |o|        | |         | |\n";
        out << "       |.|        | |         | |\n";
        out << "_____\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n" << std::endl;
        out.close();
        std::cout << "shrubbery created in " << target << "_shrubbery" << std::endl;
    } catch (const std::ios_base::failure& e) { std::cerr << "Exception : " << e.what() << std::endl; }
}