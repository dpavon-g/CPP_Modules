#include "MutantStack.hpp"

int myMain()
{
    std::cout << "\n--- Creamos el MutantStack ---\n" << std::endl;
    MutantStack<int> mstack;
    int num;

    num = 5;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    num = 17;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    std::cout << "Número en el top: " << mstack.top() << std::endl;

    std::cout << "\n--- Quitamos el top ---\n"
              << std::endl;
    mstack.pop();

    std::cout << "Total de números: " << mstack.size() << std::endl;

    num = 3;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    num = 5;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    num = 737;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    num = 0;
    std::cout << "Agregamos número: " << num << std::endl;
    mstack.push(num);

    std::cout << "Total de números: " << mstack.size() << std::endl;
    std::cout << "Número en el top: " << mstack.top() << std::endl;
    std::cout << "Puntero al número mas nuevo: " << *mstack.end() << std::endl;
    std::cout << "Puntero al número mas antiguo: " << *mstack.begin() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    std::cout << "--- Iteramos el MutantStack hacia delante ---" << std::endl;
    std::cout << "Ahora el iterador apunta al número: " << *it << std::endl;
    --it;
    std::cout << "--- Iteramos el MutantStack hacia atras ---" << std::endl;
    std::cout << "Ahora el iterador apunta al número: " << *it << std::endl;

    std::cout << "\n--- Iteramos el MutantStack con un while ---" << std::endl;
    while (it != ite)
    {
        std::cout << "Número en la pila: " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

int exMain()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

int myMainWithList()
{
    std::cout << "\n--- Creamos la lista ---\n" << std::endl;
    std::list<int> myList;
    int num;

    num = 5;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    num = 17;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    std::cout << "Número en el final: " << myList.back() << std::endl;

    std::cout << "\n--- Quitamos el último elemento ---\n"
              << std::endl;
    myList.pop_back();

    std::cout << "Total de números: " << myList.size() << std::endl;

    num = 3;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    num = 5;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    num = 737;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    num = 0;
    std::cout << "Agregamos número: " << num << std::endl;
    myList.push_back(num);

    std::cout << "Total de números: " << myList.size() << std::endl;
    std::cout << "Número en el final: " << myList.back() << std::endl;

    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();

    ++it;
    std::cout << "--- Iteramos la lista hacia adelante ---" << std::endl;
    std::cout << "Ahora el iterador apunta al número: " << *it << std::endl;
    --it;
    std::cout << "--- Iteramos la lista hacia atrás ---" << std::endl;
    std::cout << "Ahora el iterador apunta al número: " << *it << std::endl;

    std::cout << "\n--- Iteramos la lista con un while ---" << std::endl;
    while (it != ite)
    {
        std::cout << "Número en la lista: " << *it << std::endl;
        ++it;
    }
    return 0;
}

int main()
{
    std::cout << "--- My main ---\n" << std::endl;
    myMain();
    std::cout << "\n\n--- Ex main ---\n" << std::endl;
    exMain();
    std::cout << "\n\n--- My main with list ---\n" << std::endl;
    myMainWithList();
    return (0);
}