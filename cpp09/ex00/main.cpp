#include "BitcoinExchange.hpp"

void readFile(char *name) {

    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open '" << name << "' file." << std::endl;
        return;
    }
    
    file.close();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Could not open file." << std::endl;
    }
    else {
        BitcoinExchange database;
        readFile(argv[1]);
    }
}