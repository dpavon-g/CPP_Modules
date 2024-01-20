#include "BitcoinExchange.hpp"

bool validDate(std::string date) {
    int year, month, day;

    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!isdigit(date[i])) {
            return false;
        }
    }


    std::stringstream ss(date);
    ss >> year;
    ss.get();
    ss >> month;
    ss.get();
    ss >> day;

    if (month < 1 || month > 12)
        return false;
        
    if (day < 1 || day > 31)
        return false;

    return true;
}


BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open database." << std::endl;
        exit(-1);
    }
    std::string line;
    std::getline(file,line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float valor;
        if (std::getline(ss, date, ',')) {
            if (validDate(date)) {
                ss >> valor;
                if (!ss.fail()) {
                    this->setBitcoinPrice(date, valor);
                }
                else {
                    std::cout << "Error: bad float on date => " << date << std::endl;
                }
            }
            else {
                std::cout << "Error: bad database input => " << date << std::endl;
            }
        }
    }
    std::cout << "Database added :)" << std::endl;
    file.close();
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Default destructor created" << std::endl;
}

void BitcoinExchange::setBitcoinPrice(std::string date, float price) {
    _bitcoinPrice[date] = price;
}

std::map<std::string, float> BitcoinExchange::getBitcoinPrice() {
    return (_bitcoinPrice);
}


