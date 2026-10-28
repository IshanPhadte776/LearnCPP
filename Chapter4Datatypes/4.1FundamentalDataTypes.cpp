#include <iostream>

int main () {

    //2 Bytes
    short x = 32767; // Maximum value for a short   

    //4 Bytes
    int y = 2147483647; // Maximum value for an int

    //4 / 8 Bytes depending on the system
    long z = 9223372036854775807; // Maximum value for a long long

    //8 Bytes
    long long w = 9223372036854775807; // Maximum value for a

    std::cout << "Hello, World!" << std::endl;

}

//default of a decimal is a double, if you want to make it a float, you need to add an f at the end of the number, ie. 3.14f