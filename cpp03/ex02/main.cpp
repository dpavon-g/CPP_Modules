#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap	myScav("Juan");
	ScavTrap	myScav2;
	FragTrap	myFrag("Pepe");
	FragTrap	myFrag2;

	myScav2 = myScav;
	myFrag2 = myFrag;

	std::cout << myScav2.getName() << std::endl;
	std::cout << myScav.getHitPoints() << std::endl;
	std::cout << myFrag.getName() << std::endl;
	std::cout << myFrag.getHitPoints() << std::endl;
	std::cout << myFrag.getAttackDamage() << std::endl;
	myFrag.highFiveGuys();
	myScav2.attack("Andres");
	myScav.guardGate();

}