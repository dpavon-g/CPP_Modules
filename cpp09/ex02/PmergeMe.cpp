#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string _numbers) {
    std::istringstream ss(_numbers);
    char numero[256];
    size_t num;

    while (ss >> numero) {
        num = atoi(numero);
        my_vector.push_back(num);
    }
}

void PmergeMe::showVector() {
    std::cout << "After:    ";
    for (std::vector<size_t>::iterator it = my_vector.begin(); 
        it != my_vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void insertSort(std::vector<size_t> &myVector) {
    size_t n = myVector.size();

    for (size_t i = 1; i < n; ++i) {
        size_t current = myVector[i];
        size_t j = i;

        while (j > 0 && myVector[j - 1] > current) {
            myVector[j] = myVector[j - 1];
            --j;
        }

        myVector[j] = current;
    }
}
void insertNumber(std::vector<size_t> &myVector, size_t number) {
    size_t n = myVector.size();
    for (size_t i = 1; i < n; ++i) {
        if (myVector[i] > number) {
            myVector.insert(myVector.begin() + i, number);
            return ;
        }
    }
}

void PmergeMe::sortVector() {
    size_t  i = 0;
    size_t  num_aux;
    bool    impar = false;
    clock_t start_time = clock();
    size_t last = 0;

    if (my_vector.size() % 2 != 0) {
        impar = true;
        last = my_vector.size() - 1;
        my_vector.pop_back();
        (void)last;
    }
    for (std::vector<size_t>::iterator it = my_vector.begin();
        it != my_vector.end(); ++it) {
        if (i < my_vector.size() - 1 && my_vector[i] > my_vector[i + 1]) {
            num_aux = my_vector[i];
            my_vector[i] = my_vector[i + 1];
            my_vector[i + 1] = num_aux;
        }
        i++;
    }
    // insertSort(my_vector);
    if (impar == true) {
        insertNumber(my_vector, last);
    }
    clock_t end_time = clock();
    this->showVector();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << my_vector.size() << " elements: " << elapsed_time << " us" << std::endl;
    (void)impar;
}

PmergeMe::~PmergeMe() {}
