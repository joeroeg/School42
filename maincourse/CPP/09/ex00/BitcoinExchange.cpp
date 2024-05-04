#include "BitcoinExchange.hpp"

/**
 * @brief ft_stof converts a string to a float using an std::istringstream object.
 * @note This code creates an std::istringstream object initialized with the input string str, then uses the >> operator to extract an integer value into num.
 * @note it was the standard way to convert strings to integers in C++98 before the introduction of std::stoi in C++11.
*/
float ft_stof(std::string s) {
    float num;
    std::istringstream(s) >> num;
    return num;
}

BitcoinExchange::BitcoinExchange(void) { return; }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange::~BitcoinExchange() { return; }
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
    if (this != &rhs) {
        _dataMap = rhs._dataMap;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }

    std::string line; // create a string to store the line
    std::getline(file, line); // skip the first line
    while (std::getline(file, line)) { // read the file line by line
        std::istringstream iss(line); // create an input string stream
        std::string dateStr, valueStr; // create two strings to store the date and value
        if (std::getline(iss, dateStr, ',') && std::getline(iss, valueStr, ',')) {
            float value = ft_stof(valueStr); // convert the value string to a float (we need to use ft_stof because std::stof is not available in C++98
            _dataMap[dateStr] = value; // store the date and value in the map
            // std::cout << dateStr << " " << value << std::endl; // debug
        }
        else {
            std::cerr << "Error: invalid line." << std::endl;
        }
    }
    file.close();
}


float BitcoinExchange::getExchangeRate(const std::string& date) const {
    float closestRate = -1.0f;
    std::string closestDate;


    for (BitcoinPrices::const_iterator it = _dataMap.begin(); it != _dataMap.end(); ++it) {
        const std::string& currentDate = it->first;
        if (currentDate == date) {
            return it->second;
        }
        else if (currentDate < date && (closestDate.empty() || currentDate > closestDate)) {
            closestDate = currentDate;
            closestRate = it->second;
        }
    }

    return closestRate;
}

bool isDateFormatValid(const std::string& dateStr) {
    if (dateStr.size() != 10)
        return false;
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(dateStr[i]))
            return false;
    }
    std::string monthStr = dateStr.substr(5, 2);
    int month = atoi(monthStr.c_str());
    if (month < 1 || month > 12)
        return false;
    return true;
}



void BitcoinExchange::calculateBitcoinValue(const char* filename, BitcoinExchange& exchange) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr, '|')) {
            float value = ft_stof(valueStr);
            if (!isDateFormatValid(dateStr)) {
                std::cerr << "Error: invalid date format" << std::endl;
                continue;
            }
            if (value <= 0) {
                std::cerr << "Error: not a positive number" << std::endl;
                continue;
            }
            else if (value > 1000) {
                std::cerr << "Error: too large number" << std::endl;
                continue;
            }
            float exchangeRate = exchange.getExchangeRate(dateStr);
            if (exchangeRate != -1.0f) {
                std::cout << dateStr << " => " << value << " = " << (value * exchangeRate) << std::endl;
            } else {
                std::cerr << "Error: no exchange rate found for date " << dateStr << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    file.close();
}

