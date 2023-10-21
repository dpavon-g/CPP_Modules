#include "Bureaucrat.hpp"

int main() {
	std::cout << "\n---Bureaucrat creation---" << std::endl;
	Bureaucrat *heapBureau = new Bureaucrat("Pepe", 150);
	Bureaucrat stackBureau("Jose", 0);
	Bureaucrat copyBureau(stackBureau);

	std::cout << "\n---Bureaucrat getters test---" << std::endl;
	std::cout << "Name: " << heapBureau->get_name() << ", grade: " << heapBureau->get_grade() << std::endl;
	std::cout << "Name: " << stackBureau.get_name() << ", grade: " << stackBureau.get_grade() << std::endl;

	std::cout << "\n---Bureaucrat good increment and decrement test---" << std::endl;
	try {
		heapBureau->increment_grade(100);
		std::cout << *heapBureau << std::endl;
	} catch (Bureaucrat::GradeTooHighException& ex) {
		std::cout << ex.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& ex) {
		std::cout << ex.what() << std::endl;
	}	
	try {
		stackBureau.decrement_grade(100);
		std::cout << stackBureau << std::endl;
	} catch (Bureaucrat::GradeTooHighException& ex) {
		std::cout << ex.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& ex) {
		std::cout << ex.what() << std::endl;
	}


	std::cout << "\n---Bureaucrat destructors test---" << std::endl;
	delete (heapBureau);
	// system("leaks a.out");
}