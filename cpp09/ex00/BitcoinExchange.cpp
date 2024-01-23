#include "BitcoinExchange.hpp"

int convertDateToDays(const std::string &date){
    int year, month, day;
    std::istringstream stream(date);
    char dash;
    int days;

    stream >> year >> dash >> month >> dash >> day;

    days = year * 365 + month * 30 + day;
    return days;
}

bool validDate(std::string date) {
    std::stringstream ss(date);
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

void calculatePrice(std::string date, float value, std::map<std::string, float> Prices) {
    std::cout << date << " => " << value << " = ";
    int dateDays = convertDateToDays(date);
    int mapDays = 0;
    int diff;
    int lastDiff = 1;
    std::string nearestDate;
    std::map<std::string, float>::iterator iter = Prices.begin();
    while (iter != Prices.end()) {
        mapDays = convertDateToDays(iter->first);
        diff = mapDays - dateDays;
        if (diff == 0) {
            std::cout << iter->second * value << std::endl;
            return;
        }
        else if (diff < 0) {
            if (lastDiff == 1) {
                nearestDate = iter->first;
                lastDiff = diff;
            }
            else if (lastDiff < diff) {
                nearestDate = iter->first;
                lastDiff = diff;
            }
        }
        ++iter;
    }
    std::cout << Prices[nearestDate] * value << std::endl;
    (void)date;
    (void)value;
    (void)Prices;
}

void BitcoinExchange::readFile(char *name) {
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open '" << name << "' file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file,line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float value;

        if (std::getline(ss >> std::ws, date, ' ')) {
            if (validDate(date)) {    
                if (ss.get() != '|') {
                    std::cout << "Error: bad input on date => " << date << std::endl;
                }
                else if (ss.get() != ' ') {
                    std::cout << "Error: bad input on date => " << date << std::endl;
                }
                else {
                    ss >> value;
                    if (!ss.fail()) {
                        if (value <= 0) {
                            std::cout << "Error: not a positive number." << std::endl;
                        }
                        else if (value >= 1000) {
                            std::cout << "Error: too large number." << std::endl;
                        }
                        else {
                            calculatePrice(date, value, this->getBitcoinPrice());
                        }
                    }
                    else {
                        std::cout << "Error: bad float on date => " << date << std::endl;
                    }
                }
            }
            else 
                std::cout << "Error: bad input => " << date << std::endl;
        }
    }
    file.close();
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
        float value;
        if (std::getline(ss, date, ',')) {
            if (validDate(date)) {
                ss >> value;
                if (!ss.fail()) {
                    this->setBitcoinPrice(date, value);
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
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setBitcoinPrice(std::string date, float price) {
    _bitcoinPrice[date] = price;
}

std::map<std::string, float> BitcoinExchange::getBitcoinPrice() {
    return (_bitcoinPrice);
}
