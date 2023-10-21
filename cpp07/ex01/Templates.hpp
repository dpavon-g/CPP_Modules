#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template<typename T>
void iter(T *dirArray, size_t size, void(*f)(T const &)) {
	int i = 0;

	while (i < (int)size) {
		f(dirArray[i]);
		i++;
	}
}

#endif
