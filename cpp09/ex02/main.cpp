#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Error asd" << std::endl;
        return (-1);
    }
    else {
        PmergeMe merger(argv);
        merger.sortVector();
        merger.sortList();
        return (0);
    }
}