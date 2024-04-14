#include "Sed.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./a.out <filename> <to_find> <replace>." << std::endl;
        return 1;
    }
    else
    {
        Sed sed(argv[1]);
        sed.replace(argv[2], argv[3]);
    }

    // try {
    //     Sed sed(argv[1]);
    //     sed.replace(argv[2], argv[3]);
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return 1;
    // }
    return 0;
}

