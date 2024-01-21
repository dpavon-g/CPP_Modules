#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>

class BitcoinExchange
{

private:
    std::map<std::string, float> _bitcoinPrice;
public:
    void setBitcoinPrice(std::string date, float price);
    std::map<std::string, float> getBitcoinPrice();
    void readFile(char *name);
    BitcoinExchange();
    ~BitcoinExchange();
};

#endif