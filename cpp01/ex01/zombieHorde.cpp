#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    int i;

    Zombie* zombieHorde = new Zombie[N];
    i = 0;
    while (i < N)
    {
        zombieHorde[i].set_name(name);
        i++;
    }
    return (zombieHorde);

}