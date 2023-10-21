#include <iostream>

int main() {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "---Show direction---" << std::endl;
	std::cout << "String direction:	" << &string << std::endl;
	std::cout << "Reference direction:	" << &stringREF << std::endl;
	std::cout << "Pointer direction:	" << stringPTR << std::endl << std::endl;
	std::cout << "---Show string---" << std::endl;
	std::cout << "String:			" << string << std::endl;
	std::cout << "Pointer string:		" << *stringPTR << std::endl;
	std::cout << "Reference string:	" << stringREF << std::endl;
}