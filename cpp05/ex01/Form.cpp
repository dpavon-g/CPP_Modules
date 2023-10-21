#include "Form.hpp"

Form::Form(): _name("Default name"), _signed(false), _sign_grade(150), _execute_grade(150)  {
	std::cout << "Default <Form> constructor called" << std::endl;
}

Form::Form(Form &copy): _name(copy.get_name()), _signed(false), _sign_grade(copy.get_sign_grade()), _execute_grade(copy.get_execute_grade())  {
	std::cout << "Copy <Form> constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execute_grade): _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)  {
	if (this->_sign_grade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_sign_grade > 150)
		throw (Form::GradeTooLowException());
	if (this->_execute_grade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_execute_grade > 150)
		throw (Form::GradeTooLowException());
	std::cout << "Name <Form> constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "<Form> destructor called" << std::endl;
}

Form& Form::operator=(const Form &copy) {
	this->_signed = copy.get_signed();
	return (*this);
}

std::string Form::get_name() const {
	return (this->_name);
}
bool Form::get_signed() const {
	return (this->_signed);
}
int  Form::get_sign_grade() const {
	return (this->_sign_grade);
}

int Form::get_execute_grade() const {
	return (this->_execute_grade);
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "<" << form.get_name() << ">, execution grade <" << form.get_execute_grade() << ">" << ", sign grade <" << form.get_sign_grade() << ">"; 
	return os;
}

void	Form::beSigned(const Bureaucrat &b) {
	if (this->get_sign_grade() >= b.get_grade())
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
		
}