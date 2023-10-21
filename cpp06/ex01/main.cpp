#include "Serializer.hpp"

int main() {
    Data *data = new Data;
    data->character = 'A';
    data->value = 42;
    Serializer mySerial;

    std::cout << "data: " << data << std::endl;
    std::cout << "data_value: " << data->value << std::endl;
    
    uintptr_t point = mySerial.serialize(data);
    Data *dataSerialized = mySerial.deserialize(point);

    std::cout << "dataSerialized: " << dataSerialized << std::endl;
    std::cout << "dataSerialized_value: " << dataSerialized->value << std::endl;
}