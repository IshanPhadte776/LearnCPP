

#include <iostream>

int main () {
    std::cout << "" << std::endl;

    //Narrowing Converison = converting a variable from a wider, biugger data type to a smaller one

    //Direct Initialization

    int a(5);

    //Copy Initialization 

    int b = 4;

    //direct brace initialization 

    //int c {3.5}; //direct brace initialization, doesn't allow for implicit conversion

    double f = static_cast<double>(b);

}