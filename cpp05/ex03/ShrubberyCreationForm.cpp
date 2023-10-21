#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Target Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form(copy), _target(copy._target) {
	std::cout << "Copy Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	this->_target = form.getTarget();
	Form::operator=(form);
    return *this;
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->get_signed() == false)
		throw (Form::NotSignedException());
	else {
		if (this->get_execute_grade() >= executor.get_grade())
		{
			std::ofstream archivo;
			archivo.open(this->getTarget() + "_Shrubbery", std::ios::out);
			const char* textoASCII = "               * *    \n"
                             "           *    *  *  \n"
                             "      *  *    *     *  *\n"
                             "     *     *    *  *    *\n"
                             " * *   *    *    *    *   *\n"
                             " *     *  *    * * .#  *   *\n"
                             " *   *     * #.  .# *   *\n"
                             "  *     \"#.  #: \"# * *    *\n"
                             " *   * * \"#. ##\"       *\n"
                             "   *       \"###\n"
                             "             \"##\n"
                             "              ##.\n"
                             "              .##:\n"
                             "              :###\n"
                             "              ;###\n"
                             "            ,####.\n"
                             "/\\/\\/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\/\n";
                             
			archivo << textoASCII;
			archivo.close();
		}
		else
			throw (Form::GradeTooLowException());
	}
}
