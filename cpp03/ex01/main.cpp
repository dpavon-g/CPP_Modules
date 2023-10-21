#include "ScavTrap.hpp"

int main() {
    ScavTrap myScav("Juan");
	ScavTrap myScav2;

	myScav2 = myScav;

	std::cout << myScav2.getName() << std::endl;
	std::cout << myScav.getHitPoints() << std::endl;
	myScav2.attack("Andres");
	myScav.guardGate();
}