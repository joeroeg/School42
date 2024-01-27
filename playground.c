#include <unistd.h>

int main() {
    int x = 1;
    // switch(x) {
    //     case 1:
	// 		write(1, "X=1\n", 4);
    //         break;
    // }

    if(x == 1)
		write(1, "X=1\n", 4);

    return 0;
}
