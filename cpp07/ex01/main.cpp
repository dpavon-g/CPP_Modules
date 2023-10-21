#include "Templates.hpp"

void    showElement(int const &x) {
    std::cout << x << std::endl;
}

int main() {
    int myArray[] = {0, 10, 20, 30, 40};
    size_t size = sizeof(myArray) / sizeof(myArray[0]);

    std::cout << "Ejecución función iterar elementos en el array" << std::endl;
    ::iter(myArray, size, showElement);
}