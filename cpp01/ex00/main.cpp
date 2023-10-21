#include "Zombie.hpp"

int main() {
    Zombie* juan;
    
    juan = newZombie("Zombie0");
    randomChump("Zombie1");
    delete juan;
    return (0);
}