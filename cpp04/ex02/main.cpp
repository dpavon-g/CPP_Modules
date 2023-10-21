#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	int totalAnimales = 10;
	const Animal*	arrayAnimal[totalAnimales];

	std::cout << "\n\n\nPrueba de creación de array animales\n" << std::endl;
	int contador = 0;
	while (contador < totalAnimales) {
		if (contador % 2 == 0)
			arrayAnimal[contador] = new Dog();
		else
			arrayAnimal[contador] = new Cat();
		std::cout << "Animal " << contador << ": creado" << std::endl;
		contador++;
	}

	std::cout << "\n\n\nAnimal is going to make a sound:" << std::endl;
	arrayAnimal[1]->makeSound();

	std::cout << "\n\n\nPrueba de liberación de array de animales\n" << std::endl;
	contador = 0;
	while (contador < totalAnimales) {
		delete arrayAnimal[contador];
		std::cout << "Animal " << contador << ": eliminado" << std::endl;
		contador++;
	}
	system("leaks a.out");
	return 0;
}