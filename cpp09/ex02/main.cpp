#include "PmergeMe.hpp"

bool validString(const char* str) {
    std::istringstream ss(str);
    char numero[256];

    while (ss >> numero) {
        for (int i = 0; numero[i] != '\0'; ++i) {
            if (!isdigit(numero[i])) {
                std::cout << "Not string: " << numero[i] << std::endl;
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
            std::cout << "Before:   " << argv[1] << std::endl;
            PmergeMe merger(argv[1]);
            merger.sortVector();
            return (0);
        }
        else {
            std::cout << "Error" << std::endl;
            return (-1);
        }
    }
}