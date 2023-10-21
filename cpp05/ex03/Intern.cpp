#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Form*    Intern::makeForm(std::string formName, std::string targetForm) {

    if (formName == "Robotomy request")
        return (new RobotomyRequestForm(targetForm));
    else if (formName == "Shrubbery request")
        return (new ShrubberyCreationForm(targetForm));
    else if (formName == "Presidential request")
        return (new PresidentialPardonForm(targetForm));
    else
        throw (Intern::invalidForm());
}