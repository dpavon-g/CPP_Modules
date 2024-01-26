#include "PmergeMe.hpp"

#include <sstream>

bool validString(const char* str) {
    std::istringstream ss(str);
    char numero[256];

    while (ss >> numero) {
        for (int i = 0; numero[i] != '\0'; ++i) {
            if (!isdigit(numero[i])) {
                return false;
            }
        }

        if (ss.peek() != ' ' && !ss.eof()) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return (-1);
    }
    else {
        if (validString(argv[1]) == true) {
            std::cout << "Before: " << argv[1] << std::endl;
            return (0);
        }
        else {
            std::cout << "Error" << std::endl;
            return (-1);
        }
    }
}