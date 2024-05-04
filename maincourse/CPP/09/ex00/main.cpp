#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    (void)argv;
    if (argc != 2) {
        std::cerr << "Usage: ./bitcoin path" << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange exchange("data.csv");
    exchange.calculateBitcoinValue(argv[1], exchange);
    return EXIT_SUCCESS;
}
