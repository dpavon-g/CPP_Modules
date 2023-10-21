#include "Convert.hpp"

Convert::Convert() {
    std::cout << "Default constructor called" << std::endl;
}

Convert::Convert(Convert const &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Convert &Convert::operator=(Convert const &copy) {
    (void)copy;
    return *this;
}

Convert::~Convert() {
    std::cout << "Default destructor called" << std::endl;
}

void Convert::startConvert(const std::string &lit) {
    /*
        Si encuentra los casos especiales lo que hago es mostrarlos directamente
        y salirme del programa.
    */
    if (lit == "inf" || lit == "-inf" || lit == "nan") {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << lit << "f" << std::endl;
		std::cout << "double: " << lit << std::endl;
		return ;
    }
    else if (lit == "inff" || lit == "-inff" || lit == "nanf") {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << lit << std::endl;
		std::cout << "double: " << lit.substr(0, lit.size()-1) << std::endl;
		return ;
    }

    /*
        Ahora lo que haremos será comprobar el sufijo del literal
        En el caso de que tenga una f al final la quitaremos.
    */
    std::string strNoF;
    if (lit[lit.size() - 1] == 'f')
        strNoF = lit.substr(0, lit.size() - 1);
    else 
        strNoF = lit;
    
    if (lit.size() == 1 && std::isprint(lit[0]) && !std::isdigit(lit[0]))
        std::cout << "char: " << lit[0] << std::endl;
    else {
        
        /*
            Ahora lo que haremos será comprobar que el string que le hemos pasado pueda entrar en un double.
            De esta forma nos aseguramos que es un número y si tiene decimales, podremos mostrarlo como char 
            igualmente.
        */
        double d;
        std::istringstream strChar(strNoF);
        if (!(strChar >> d).fail()) {
            /*
                Ahora se comprueba que el valor que se le ha pasado no tenga espacios o caracteres que puedan
                Estar separando el número y que no dé un falso positivo
            */
            std::string trash;
			std::getline(strChar, trash);
            if (trash.empty()) {
                int integer = static_cast<int>(d);
                if (integer >= 32 && integer <= 126) {
					std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
				} else {
					std::cout << "char: Non displayable" << std::endl;
				}
            }
            else
			    std::cout << "char: impossible" << std::endl;
        } else {
			std::cout << "char: impossible" << std::endl;
		}
    }

    /*
        Ahora haremos la conversión de string a integer para comprobar que se cumpla
        el maxint y el minint. En caso que sobrepase alguno de estos valores mostraremos un error.
    */
    std::istringstream strInt(strNoF);
    int integer;
    if (!(strInt >> integer).fail())
        std::cout << "int: " << integer << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    std::istringstream strFloat(strNoF);
    float myFloat;
    if (!(strFloat >> myFloat).fail()) {
        std::string trash;
        std::getline(strFloat, trash);
        if (trash.empty())
            std::cout << std::fixed << "float: " << myFloat << "f" << std::endl;
        else
            std::cout << "float: impossible" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;

    std::istringstream strDouble(strNoF);
    double myDouble;
    if (!(strDouble >> myDouble).fail()) {
        std::string trash;
        std::getline(strDouble, trash);
        if (trash.empty())
            std::cout << std::fixed << "double: " << myDouble << std::endl;
        else
            std::cout << "double: impossible" << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}