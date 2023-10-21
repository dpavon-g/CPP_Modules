#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors

Bureaucrat::Bureaucrat(): _name("Default Bureaucrat"), _grade(150) {
	std::cout << "Default <Boureaucrat> constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int value): _name(name), _grade(value) {
	if (value < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (value > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Name <Bureaucrat> constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy): _name(copy.get_name()), _grade(copy.get_grade()) {
	std::cout << "Name <Bureaucrat> copy constructor called" << std::endl;
}

// Getters

std::string Bureaucrat::get_name() const {
	return this->_name;
}

int Bureaucrat::get_grade() const {
	return this->_grade;
}

// Extra functions

void    Bureaucrat::increment_grade(int value) {
	this->_grade = this->_grade - value;
	if (this->get_grade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->get_grade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrement_grade(int value) {
	this->_grade = this->_grade + value;
	if (this->get_grade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->get_grade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << "<" << this->get_name() << "> signed <" << f.get_name() << ">" << std::endl;
	} catch (Form::GradeTooLowException& ex) {
		std::cout << "<" << this->get_name() << "> couldn't sign <" << f.get_name() << "> because <" << ex.what() << std::endl; 
	}
}

void	Bureaucrat::executeForm(Form const &form){
	try {
		form.execute(*this);
		std::cout << "<" << this->get_name() << "> executed " << form.get_name() << std::endl;
	} catch (Form::NotSignedException) {
		std::cout << "Form not signed!" << std::endl;
	} catch (Form::GradeTooLowException) {
		std::cout << "Not enough grade to execute it!" << std::endl;
	}
}

// Operators overload

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau) {
	os << "<" << bureau._name << ">, bureaucrat grade <" << bureau._grade << ">"; 
	return os;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other.get_grade();
	}
	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat() {
	std::cout << "<Bureaucrat> destructor called" << std::endl;
}

