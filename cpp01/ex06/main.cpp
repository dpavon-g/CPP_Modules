#include <iostream>
#include <fstream>

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl new_harl;

    if (argc == 2)
        new_harl.complain(argv[1]);
    else
        std::cout << "Invalid arguments" << std::endl;
}