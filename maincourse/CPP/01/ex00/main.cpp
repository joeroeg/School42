#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    Zombie stackZombie("StackZombie");
    stackZombie.announce();
    return 0;
}
