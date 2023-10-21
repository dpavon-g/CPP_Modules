#include "Span.hpp"

int main(void) {
    Span mySpan(5);
    
    std::cout << "--- Add number test ---" << std::endl;
    int i = 0;
    while (i < 10) {
        try {
            mySpan.addNumber(i);
            std::cout << "Number: <" << i << "> correctly added" << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        i++;
    }

    std::cout << "\n--- Shortest Span test ---" << std::endl;

    int random1 = rand() % 50;
    int random2 = rand() % 50;
    int random3 = rand() % 50;
    std::cout << "Number 1: " << random1 << std::endl;
    std::cout << "Number 2: " << random2 << std::endl;
    std::cout << "Number 3: " << random3 << std::endl;
    Span mySpan2(3);
    mySpan2.addNumber(random1);
    mySpan2.addNumber(random2);
    mySpan2.addNumber(random3);
    std::cout << "Shortest Span: " << mySpan2.shortestSpan() << std::endl;

    std::cout << "\n--- Empty Span test ---" << std::endl;
    Span mySpan3(3);
    try {
        std::cout << "Shortest Span: " << mySpan3.shortestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Longest Span test ---" << std::endl;

    random1 = rand() % 50;
    random2 = rand() % 50;
    random3 = rand() % 50;
    std::cout << "Number 1: " << random1 << std::endl;
    std::cout << "Number 2: " << random2 << std::endl;
    std::cout << "Number 3: " << random3 << std::endl;
    Span mySpan4(3);
    mySpan4.addNumber(random1);
    mySpan4.addNumber(random2);
    mySpan4.addNumber(random3);
    std::cout << "Longest Span: " << mySpan4.longestSpan() << std::endl;

    std::cout << "\n--- Empty Span test ---" << std::endl;
    Span mySpan5(3);
    try {
        std::cout << "Longest Span: " << mySpan5.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- 10.000 numbers test ---" << std::endl;
    int total = 10000;
    Span macroSpan(total);
    int counter = 0;
    while (counter < total) {
        try {
            macroSpan.addNumber(counter);
            if (counter % 1000 == 0)
                std::cout << "Number: <" << counter << "> correctly added" << std::endl;
            else if (counter == total - 1)
                std::cout << "Number: <" << counter << "> correctly added" << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        counter++;
    }

    std::cout << "\n--- Shortest and longest Span test ---" << std::endl;
    std::cout << "Shortest Span: " << macroSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << macroSpan.longestSpan() << std::endl;
    
    std::cout << "\n--- Asignation operator test ---" << std::endl;
    Span macroSpan2 = macroSpan;
    std::cout << "Shortest Span: " << macroSpan2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << macroSpan2.longestSpan() << std::endl;
    try {
        macroSpan2.addNumber(10001);
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- AddRange function test ---" << std::endl;
    Span newVector(5);
    int array[6] = {1, 2, 3, 4, 5};
    std::cout << "--- Adding range ---" << std::endl;
    newVector.addRange(array, array + 5);
    std::cout << "--- Getting numbers ---" << std::endl;
    newVector.getNumbers();
}

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
// }
