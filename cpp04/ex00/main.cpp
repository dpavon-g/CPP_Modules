#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "\n---Construction of animals\n" << std::endl;
	const Animal*		Alex = new Animal();
	const Animal*		kira = new Dog();
	const Animal*		misi = new Cat();

	std::cout << "\n---Sounds of animals\n" << std::endl;
	Alex->makeSound();
	kira->makeSound();
	misi->makeSound();

	std::cout << "\n---Son class using father funtions\n" << std::endl;
	misi->Animal::makeSound();
	kira->Animal::makeSound();
	std::cout << kira->Animal::getType() << std::endl;
	std::cout << misi->Animal::getType() << std::endl;

	std::cout << "\n---Destruction of animals\n" << std::endl;
	delete Alex;
	delete kira;
	delete misi;



	std::cout << "\n\n\n---Construction of WrongAnimals\n" << std::endl;
	const WrongAnimal*		WrongAlex = new WrongAnimal();
	const WrongAnimal*		Wrongkira = new WrongDog();
	const WrongAnimal*		Wrongmisi = new WrongCat();

	std::cout << "\n---Sounds of WrongAnimals\n" << std::endl;
	WrongAlex->makeSound();
	Wrongkira->makeSound();
	Wrongmisi->makeSound();

	std::cout << "\n---Son class using father funtions\n" << std::endl;
	Wrongmisi->WrongAnimal::makeSound();
	Wrongkira->WrongAnimal::makeSound();
	std::cout << Wrongkira->WrongAnimal::getType() << std::endl;
	std::cout << Wrongmisi->WrongAnimal::getType() << std::endl;

	std::cout << "\n---Destruction of WrongAnimals\n" << std::endl;
	delete WrongAlex;
	delete Wrongkira;
	delete Wrongmisi;
	system("leaks a.out");
}