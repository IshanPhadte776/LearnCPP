#include <iostream>

int main () {
    std::cout << "" << std::endl;

    std::cout << 3 + 4 << " \n"; // prints 7
    std::cout << 3 + 4 - 5 << " \n"; // prints 2
    std::cout << 2 + 3 * 4 << " \n"; // prints 14


    int x {2};
    std::cout << ( x = 5) << '\n'; // 5 is returned from this statement
}