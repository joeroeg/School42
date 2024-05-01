#include <cmath>
#include <exception>
#include <iostream>
#include "../include/Parser.hpp"

int main(int argc, char **argv) {
	if (argc < 2 || argc > 2)
		return (std::cout << "bad arguments" << std::endl, 1);
	try {
		Parser value(argv[1]);
		value.setType();
		value.printValue();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
