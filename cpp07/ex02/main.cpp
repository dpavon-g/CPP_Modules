#include <iostream>
#include <cstdlib>
#include "Array.hpp"

int main()
{
    Array<int> myArray;
	std::cout << "Tamaño del array <myArray>: " << myArray.size() << std::endl;

	Array<int> myArray2(10);
	std::cout << "Tamaño del array <myArray2>: " << myArray2.size() << std::endl;

    Array<int> myArray3(myArray2);
    std::cout << "Longitud de array <myArray3> creado de <myArray2>" << std::endl;

	myArray = myArray2;
	std::cout << "Tamaño del array <myArray> despues de hacer la igualación: " << myArray3.size() << std::endl;

	try {
	Array<int> myArray4(5);

	myArray4[0] = 200;
    std::cout << "Damos valor a la primera posición del array" << std::endl;

	std::cout << "Valor del primer elemento del array: " << myArray4[0] << std::endl;

	const Array<int> constmyArray(10);
	std::cout << "Obtenemos el valor de la posición 5 del array: " <<constmyArray[5] << std::endl;

	myArray4[10] = 20;  // Throws exceptions for out of bounds
	} catch (const std::out_of_range& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}