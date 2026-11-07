#include <iostream>
#include <string>
#include <utility> 

template <typename T>
void mySwapMove() {
    T tmp {std::move(a)}; //move constructor 
    a = std::move(b); //move assignment
    b = std::move(tmp);
}

