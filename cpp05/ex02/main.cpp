#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat pepe("Pepe", 1);
	ShrubberyCreationForm form("House");
	RobotomyRequestForm form1("Robot");
	PresidentialPardonForm form2("Presidential");

	std::cout << "\n---ShrubberyCreationForm test---" << std::endl;
	try {
		pepe.signForm(form);
	} catch (Form::GradeTooLowException) {
		std::cout << "Not enough grade to sign it!" << std::endl;
	}
	pepe.executeForm(form);

	std::cout << "\n---RobotomyRequestForm test---" << std::endl;
	try {
		pepe.signForm(form1);
	} catch (Form::GradeTooLowException) {
		std::cout << "Not enough grade to sign it!" << std::endl;
	}
	pepe.executeForm(form1);


	std::cout << "\n---PresidentialPardonForm test---" << std::endl;
	try {
		pepe.signForm(form2);
	} catch (Form::GradeTooLowException) {
		std::cout << "Not enough grade to sign it!" << std::endl;
	}
	pepe.executeForm(form2);


	std::cout << "\n---Destructors of the classes---" << std::endl;
	// system("leaks a.out");
}