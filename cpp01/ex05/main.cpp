#include <iostream>
#include <fstream>

#include "Harl.hpp"

int main() {
	Harl new_harl;

    new_harl.complain("warning");
    new_harl.complain("debug");
    new_harl.complain("info");
    new_harl.complain("error");
}