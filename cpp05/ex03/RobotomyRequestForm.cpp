#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Target Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form(copy), _target(copy._target) {
    std::cout << "Copy Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
    this->_target = form.getTarget();
	Form::operator=(form);
    return *this;
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (this->get_signed() == false)
		throw (Form::NotSignedException());
	else {
		if (this->get_execute_grade() >= executor.get_grade()) {
			std::cout << "Make some drilling noises" << std::endl;
            srand(time(0));
            int numAleatorio = rand() % 2;
            if (numAleatorio == 0) 
                std::cout << "<" << this->getTarget() << "> has been robotomized sucessfully" << std::endl;
            else
                std::cout << "<" << this->getTarget() << "> robotomized has failed" << std::endl;
		}
        else 
            throw (Form::GradeTooLowException());
    }
}
