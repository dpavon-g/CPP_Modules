#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
    int value;
    char character;
};

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();
		Serializer &operator=(Serializer const &copy);
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
