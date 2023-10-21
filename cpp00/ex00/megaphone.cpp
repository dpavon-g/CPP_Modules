#include <iostream>

int main(int argc, char **argv) {
    int i;
    int j;

    i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
            {
                argv[i][j] = toupper(argv[i][j]);
            }
            j++;
        }
        std::cout << argv[i];
        i++;
        if (argv[i])
            std::cout << " ";
        else
            std::cout << "\n";
    }
    return (0);
}