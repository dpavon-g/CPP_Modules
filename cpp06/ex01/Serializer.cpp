#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "Default destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &copy) {
    (void)copy;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return (uintptr_t)ptr;
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (Data *)raw;
}