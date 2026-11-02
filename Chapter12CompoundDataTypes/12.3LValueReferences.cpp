//LValue Reference is called a reference / alias for an existing variable 

#include <iostream>

int main() {
    int x {5};
    int& ref {x}; //ref is an LValue reference to x

    cout << "x: " << x << std::endl; //5
    cout << "ref: " << ref << std::endl; //5

    ref = 10; //modifies x through the reference
    cout << "x: " << x << std::endl; //10   
    cout << "ref: " << ref << std::endl; //10

    //refs must be initialized when declared and cannot be null
    int& ref2; //error: ref2 must be initialized

    //refs cannot be reseated to refer to another variable after initialization
    int y {20};
    ref = y; //modifies x to be 20, does not reseat ref

    //refs can change the value of the original variable, but can't change what a reference refers to

    //refs are created after, and should be deleted first, it becomes ub when the original variable goes out of scope

    //By technically, refs aren't objects, they lack their own memory address, complier optimzies them by removing them and adding the oriignal variable in its place when making assembly code

}