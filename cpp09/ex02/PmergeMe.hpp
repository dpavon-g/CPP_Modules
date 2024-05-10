#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <sys/time.h>
# include <list>

class PmergeMe
{
    private:
        std::vector<size_t> my_vector;
        std::list<size_t>   my_list;
    public:
        void sortVector();
        void sortList();
        void showVector();
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe &copy);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};

#endif