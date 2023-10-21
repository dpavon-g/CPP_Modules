#include "Zombie.hpp"

int main() {
    int i;
    int totalZombies;

    totalZombies = 10;
    Zombie* my_zombieHorde;
    my_zombieHorde = zombieHorde(totalZombies, "Pepe");
    i = 0;
    while (i < totalZombies) {
        my_zombieHorde[i].announce();
        i++;
    }
    delete [] my_zombieHorde;
    return (0);
}