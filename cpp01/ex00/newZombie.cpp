#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    std::cout << z->get_name() << std::endl;
    return (z);
}