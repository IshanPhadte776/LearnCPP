#include <iostream>

int main() {
    int x{ 5 };
    std::cout << *(&x) << '\n'; // Dereferences the address of x -> prints 5

    *(&x) = 9;                  // Assigns 9 directly to the memory address of x
    std::cout << x << '\n';     // Prints 9
    return 0;

    //Pointers are objects, has its own memory address, can be reseated to point to another varaible
    //References are not objects, they don't have their own memory address, can't be reseated to point to another variable
    //Dangling pointers are allowed, dangling references are not allowed
    //Refs can't be null, pointers can be null
}