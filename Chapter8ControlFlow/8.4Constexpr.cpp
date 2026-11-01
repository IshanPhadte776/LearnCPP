#include <iostream>

int main () {
    std::cout << "" << std::endl;

    //allowed because this is a constexpr / const 
    constexpr double gravity { 9.8 };

    if constexpr (gravity == 9.8) {
        std::cout << "Earth" < '\n';
    } else {
        std::cout << "Not Earth" < '\n';
    }

}


//Because the expression is constexpr, its evaluted at compile time (True), the else branch is discarded and not added to the executable, saving instruction