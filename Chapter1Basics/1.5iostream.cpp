#include <iostream>


//Q1.
int main () {
    std::cout << "enter a number: ";
    int x{};
    std::cin >> x;

    // int y{};
    // int z{};
    // std::cin >> y;
    // std::cin >> z;

    std::cout << "You entered" << x << '\n';
    // std::cout << "You entered" << y << '\n';
    // std::cout << "You entered" << z << '\n';

    return 0;

}

//1a. 'h' -> int can't have 0, no error, just x stays w/ 0
//1b. 3.2 -> 3.2 gets converted to 3
//1c. -3 -> just stores it
//1ca -3 for unsigned int-> underflows. 
//1d "Hello" -> goes to 0
//1e. 3 billion -> just stores the max number 
//1f. 123abc -> just stores 123 
//1g  abc123 -> 0
//1h    +5 -> 5
//1u) 5b6 -> 5
