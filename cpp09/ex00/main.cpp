#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Could not open file." << std::endl;
    }
    else {
        BitcoinExchange database;
        database.readFile(argv[1]);
    }
}
