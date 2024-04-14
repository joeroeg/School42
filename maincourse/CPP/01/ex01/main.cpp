#include "Zombie.hpp"

#define N 5

int main( void ) {
    Zombie *zombie = zombieHorde(N, "ZOMBIE");

    for (size_t i = 0; i < N; i++) {
        zombie[i].announce();
    }

    // delete [] zombie means that the destructor of each zombie object will be called
    delete [] zombie;
    return 0;
}
