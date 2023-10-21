#include "Templates.hpp"

int main(void) {
    std::cout << "--- Create container with {1, 2, 3, 4, 5} ---" << std::endl;
	std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Trying to find the number 2 in the vector" << std::endl;
    try {
        std::vector<int>::iterator result = easyfind(vec, 2);
        if (result != vec.end()) {
            std::cout << "Your number is in the vector!" << std::endl;
            std::cout << "Number: " << *result << std::endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--- Cleaning the first vector ---\n" << std::endl;
    vec.clear();

    std::cout << "--- Create container with {6, 7, 8, 9, 10} ---" << std::endl;
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);

    std::cout << "Trying to find the number 2 in the vector" << std::endl;
    try {
        std::vector<int>::iterator result = easyfind(vec, 2);
        if (result != vec.end()) {
            std::cout << "Your number is in the vector!" << std::endl;
            std::cout << "Number: " << *result << std::endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--- Cleaning the second vector ---" << std::endl;
    vec.clear();
}