#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
	private:
		T* _elements;  // Puntero al array
		size_t _size;  // Tamaño del array
	public:
		Array() : _elements(NULL), _size(0) {
			std::cout << "Default <Array> constructor called" << std::endl;
		}

		Array(unsigned int n): _size(n) {
			std::cout << "Integer <Array> constructor called" << std::endl;
			_elements = new T[n];
			size_t i = 0;
			while (i < _size) {
				_elements[i] = 0;
				i++;
			}
		}

		Array(const Array &copy) : _size(copy._size) {
			std::cout << "Copy <Array> constructor called" << std::endl;
			_elements = new T[_size];
			size_t i = 0;
			while (i < _size) {
				_elements[i] = copy._elements[i];
				i++;
			}
		}

		Array&		operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;
				_size = other._size;
				_elements = new T[_size];
				size_t i = 0;
				while (i < _size) {
					_elements[i] = other._elements[i];
					i++;
				}
			}
			return *this;
		}

		T&			operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return _elements[index];
		}

		const T&	operator[](unsigned int index) const {
			if (index >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return _elements[index];
		};

		unsigned int size() const	{
			return _size ;
		}

		~Array() {
			if (_size )
				delete [] this->_elements ;
		}
};

#endif