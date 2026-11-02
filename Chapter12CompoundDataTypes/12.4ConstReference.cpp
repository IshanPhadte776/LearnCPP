#include <iostream>

int main () {
    std::cout << "" << std::endl;

    const int x = 10; // x is an LValue, but not modifiable
    const int& ref {x}; //ref is an LValue reference to x

    int y = 20; // y is an LValue and modifiable
    const int& ref2 {y}; //ref2 is an LValue reference to y
    //modifiable via y, but not via ref2

    //base is const, ref is non const -> error 

    //const lvalue reference to an rvalue can give a lifetime extension to an rvalue 

    const int& ref3 {30}; //ref3 is an LValue reference to an rvalue 30, lifetime of 30 is extended to the lifetime of ref3

}