#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\n---Bureaucrat creation---" << std::endl;
	Bureaucrat *heapBureau = new Bureaucrat("Pepe", 10);
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
	
	std::cout << "\n---Form creation---" << std::endl;
	Form house_form;
	Form *renta_form = new Form("Hacienda", 10, 0);
	Form copy_form(*renta_form);
	std::cout << "\n---Form getters test---" << std::endl;
	std::cout << "Name: " << house_form.get_name() << ", signed: " << house_form.get_signed() << ", sign grade: " << house_form.get_sign_grade() << ", execution grade: " << house_form.get_execute_grade() << std::endl;
	std::cout << "Name: " << renta_form->get_name() << ", signed: " << renta_form->get_signed() << ", sign grade: " << renta_form->get_sign_grade() << ", execution grade: " << renta_form->get_execute_grade() << std::endl;
	std::cout << "Name: " << copy_form.get_name() << ", signed: " << copy_form.get_signed() << ", sign grade: " << copy_form.get_sign_grade() << ", execution grade: " << copy_form.get_execute_grade() << std::endl;

	std::cout << "\n---Form << operator overload test---" << std::endl;
		std::cout << house_form << std::endl;
		std::cout << *renta_form << std::endl;

	std::cout << "\n---Boureaucrat sign a form test---" << std::endl;
	heapBureau->signForm(*renta_form);
	stackBureau.signForm(house_form);

	std::cout << "\n---Bureaucrat destructors test---" << std::endl;
	delete (heapBureau);
	
	std::cout << "\n---Form destructors test---" << std::endl;
	delete (renta_form);
	system("leaks a.out");
}