#include <iostream>
#include <cmath>

int main () {
    std::cout << "" << std::endl;
    //Side of the answer is the sign of the left operand 

    std::cout << 6 % 4 << std::endl; // 2
    std::cout << 6 % -4  << std::endl; // 2
    std::cout << -6 % 4 << std::endl; // -2
    std::cout << -6 % -4 << std::endl; // -2

    //This % is called the remainder operator, not modulo because we maintain the sign of the left operand

    //Exponentiation in C++
    // use std::pow 

    double res = std::pow(3.0,4.0); //3^4 = 81 (3*3*3*3) 

    //Non recommended to use ints for std::pow, powers grow exponentially, can easily lead to overflow integer widths

}