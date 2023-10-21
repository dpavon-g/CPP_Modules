#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "Intern.hpp"

int main() {
	Intern randomIntern;
	Form *formulario;
	Bureaucrat pepe("Pepe", 4);

	try {
		formulario = randomIntern.makeForm("Presidential request", "Presidencial");
		std::cout << formulario->get_name() << std::endl;
	}
	catch (Intern::invalidForm& ex) {
		std::cout << ex.what() << std::endl;
	}

	pepe.executeForm(*formulario);
	pepe.signForm(*formulario);
	// system("leaks a.out");
}