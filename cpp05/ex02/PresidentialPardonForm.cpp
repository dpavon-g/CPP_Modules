#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Target President constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form(copy), _target(copy._target) {
	std::cout << "Copy Robotomy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presiential destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
	this->_target = form.getTarget();
	Form::operator=(form);
    return *this;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->get_signed() == false)
		throw (Form::NotSignedException());
	else {
		if (this->get_execute_grade() >= executor.get_grade()) {
			std::cout << "<" << this->getTarget() << "> has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
        else 
            throw (Form::GradeTooLowException());
    }
}
