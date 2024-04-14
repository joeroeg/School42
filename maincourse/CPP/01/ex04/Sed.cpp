#include "Sed.hpp"

Sed::Sed(std::string filename) {
    _filename = filename;
    _inFile.open(_filename);
    _outFile.open(_filename + ".replace");
}

Sed::~Sed() {}

void Sed::replace(const std::string& find, const std::string& replace) {
        std::ifstream inFile(_filename);
        std::ofstream outFile(_filename + ".replace");
        if (!_inFile.is_open() || !_outFile.is_open()) {
            throw std::runtime_error("Error opening files!");
        }
        std::string line;
        while (std::getline(_inFile, line)) {
            size_t pos = 0;
            std::string newLine;
            size_t lastPos = 0;

            while ((pos = line.find(find, pos)) != std::string::npos) {
                newLine += line.substr(lastPos, pos - lastPos);
                newLine += replace;
                pos += find.length();
                lastPos = pos;
            }
            newLine += line.substr(lastPos);
            _outFile << newLine << std::endl;
        }
        _inFile.close();
        _outFile.close();
}
