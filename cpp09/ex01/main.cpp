#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return (-1);
    }
    else {
        RPN executor;
        return (executor.calculate(argv[1]));
    }
}