#include "PmergeMe.hpp"

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

PmergeMe::PmergeMe(char **argv) {
    size_t num;
    int i = 1;
    while (argv[i]) {
        if (validString(argv[i])) {
            num = atoi(argv[i]);
            my_vector.push_back(num);
            my_list.push_back(num);
        }
        else {
            std::cout << "Error" << std::endl;
            exit(-1);
        }
        i++;
    }
    std::cout << "Before:   ";
    for (std::vector<size_t>::iterator it = my_vector.begin();
        it != my_vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    this->my_list = copy.my_list;
    this->my_vector = copy.my_vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
    if (this != &copy) {
        this->my_list = copy.my_list;
        this->my_vector = copy.my_vector;
    }
    return *this;
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

void insertSortList(std::list<size_t>& myList) {
    std::list<size_t>::iterator it = myList.begin();
    ++it;

    for (; it != myList.end(); ++it) {
        size_t current = *it;
        std::list<size_t>::iterator j = it;

        while (j != myList.begin() && *(--j) > current) {
            std::list<size_t>::iterator next = j;
            ++next;
            *next = *j;
        }

        std::list<size_t>::iterator next = j;
        ++next;
        *next = current;
    }
}

void insertNumberList(std::list<size_t>& myList, size_t number) {
    std::list<size_t>::iterator it = myList.begin();
    while (it != myList.end() && *it <= number) {
        ++it;
    }
    myList.insert(it, number);
}

void insertNumber(std::vector<size_t> &myVector, size_t number) {
    size_t n = myVector.size();
    for (size_t i = 1; i < n; ++i) {
        if (myVector[i] > number) {
            myVector.insert(myVector.begin() + i, number);
            return ;
        }
    }
    myVector.push_back(number);
}

void PmergeMe::sortVector() {
    size_t  i = 0;
    size_t  num_aux;
    bool    impar = false;
    clock_t start_time = clock();
    size_t last = 0;

    if (my_vector.size() % 2 != 0) {
        impar = true;
        last = my_vector.back();
        my_vector.pop_back();
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
    insertSort(my_vector);
    if (impar == true) {
        insertNumber(my_vector, last);
    }
    clock_t end_time = clock();
    this->showVector();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e2;
    std::cout << "Time to process a range of " << my_vector.size() << " elements with std::vector   : " << elapsed_time << " us" << std::endl;
}

void PmergeMe::sortList() {
    size_t  num_aux;
    size_t  last = 0;
    bool    impar = false;
    clock_t start_time = clock();

    if (my_list.size() % 2 != 0) {
        impar = true;
        last = my_list.back();
        my_list.pop_back();
    }
    for (std::list<size_t>::iterator it = my_list.begin();
        it != my_list.end(); ++it) {
        std::list<size_t>::iterator next = it;
        ++next;
        if (next != my_list.end() && *it > *next) {
            num_aux = *it;
            *it = *next;
            *next = num_aux;
        }
    }
    insertSortList(my_list);
    if (impar == true)
        insertNumberList(my_list, last);
    clock_t end_time = clock();
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e2;
    std::cout << "Time to process a range of " << my_vector.size() << " elements with std::list     : " << elapsed_time << " us" << std::endl;
}

PmergeMe::~PmergeMe() {}
