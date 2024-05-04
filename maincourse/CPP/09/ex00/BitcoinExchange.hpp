#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <limits>

typedef std::map<std::string, float> BitcoinPrices;

class BitcoinExchange {
public:
    BitcoinExchange(void); // default constructor
    BitcoinExchange(std::string path); // constructor with path
    BitcoinExchange(const BitcoinExchange &src); // copy constructor
    ~BitcoinExchange(); // destructor
    BitcoinExchange& operator=(BitcoinExchange const& rhs); // assignation operator

    void calculateBitcoinValue(const char* filename, BitcoinExchange& exchange); // calculate bitcoin value
    float getExchangeRate(const std::string& date) const; // get exchange rate


private:
    std::map<std::string, float> _dataMap; // map to store data
};

int ft_stoi(std::string s); // convert string to int
float ft_stof(std::string s); // convert string to float
bool isDateFormatValid(const std::string& dateStr); // check if date format is valid

#endif

