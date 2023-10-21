#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = std::rand() % 3;

    if (randomNumber == 0)
        return new A;
    else if (randomNumber == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "p es de tipo A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "p es de tipo B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "p es de tipo C" << std::endl;
}

void identify(Base& p) {
    if (A* a = dynamic_cast<A*>(&p)) {
        std::cout << "p es de tipo A" << std::endl;
        (void)a;
    }
    else if (B* b = dynamic_cast<B*>(&p)) {
        std::cout << "p es de tipo B" << std::endl;
        (void)b;
    }
    else if (C* c = dynamic_cast<C*>(&p)) {
        std::cout << "p es de tipo C" << std::endl;
        (void)c;
    }
}

int main() {
    Base *base;
	base = generate();
	identify(base);
	identify(*base);
}