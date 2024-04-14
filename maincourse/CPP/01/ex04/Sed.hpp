#ifndef SED_HPP
#define SED_HPP
#include <iostream>
#include <fstream>
#include <string>


class Sed
{
private:
    std::string _filename;
    std::ifstream _inFile;
    std::ofstream _outFile;

public:
    Sed(std::string filename);
    ~Sed();

    void replace(const std::string& find, const std::string& replace);
};

#endif
