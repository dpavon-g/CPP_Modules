#include "fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     std::cout << Fixed::min( a, b ) << std::endl;
//     return 0;
// }

int main( void ) {
    Fixed a;


    Fixed const b(Fixed( 5.05f ) + Fixed( 2 ));
    Fixed c(Fixed( 5.05f ) - Fixed( 4.05f ));

    std::cout << "-  Valor de b (Suma 5.05f + 2): --- " << b << std::endl;
    std::cout << "-  Valor de c (Rest 5.05f + 4.05): --- " << c << std::endl;
    std::cout << "-  Valor de a:  " << a << std::endl;
    std::cout << "--- Preincrementamos a: ---" << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "-  Valor de a:  " << a << std::endl;
    std::cout << "--- Post incrementamos a: ---" << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "-  Valor de a:  " << a << std::endl;
    std::cout << "--- Predecrementamos a: ---" << std::endl;
    std::cout << --a << std::endl;
    std::cout << "-  Valor de a:  " << a << std::endl;
    std::cout << "--- Postdecrementamos a: ---" << std::endl;
    std::cout << a-- << std::endl;
    std::cout << "-  Valor de a:  " << a << std::endl;
    std::cout << "--- División de c entre b: ---" << std::endl;
    std::cout <<  c / b << std::endl;
    std::cout << "--- Multiplicación de c entre b: ---" << std::endl;
    std::cout <<  c * b << std::endl;
    std::cout << "Operadores de comparación:" << std::endl;
    if (c < b)
        std::cout << "c es mas pequeño que b" << std::endl;
    if (b > c)
        std::cout << "b es mas grande que c" << std::endl;
    if (c <= b)
        std::cout << "c es mas pequeño o igual que b" << std::endl;
    if (b >= c)
        std::cout << "b es mas grande o igual que c" << std::endl;
    if (c == c)
        std::cout << "c es igual que c" << std::endl;
    if (c != b)
        std::cout << "c es diferente a b" << std::endl;

    return 0;
}