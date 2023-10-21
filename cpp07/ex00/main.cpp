#include "Templates.hpp"

// int main() {
// 	int num1 = 1;
// 	int num2 = 2;

// 	std::cout << " --- Valores 1 y 2 antes ---" << std::endl;
// 	std::cout << num1 << std::endl;
// 	std::cout << num2 << std::endl;

// 	::swap(num1, num2);
// 	std::cout << "--- Valores 1 y 2 despues ---" << std::endl;
// 	std::cout << num1 << std::endl;
// 	std::cout << num2 << std::endl;

// 	std::cout << "--- Valor función min() ---"<< std::endl;
// 	std::cout << ::min(num1, num2) << std::endl;

// 	std::cout << "--- Valor función max() ---" << std::endl;
// 	std::cout << ::max(num1, num2) << std::endl;
// }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
