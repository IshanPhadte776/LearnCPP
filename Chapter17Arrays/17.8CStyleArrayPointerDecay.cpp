//c styles array can and will implicitly convert to pointers as the two concepts are similiar 

#include <iostream>

int main() {
    int prime[5]{ 2, 3, 5, 7, 11 };

    // The array variable itself evaluates to the address of the first element:
    std::cout <<  prime << '\n';   // Prints memory address of prime[0]
    std::cout <<  &print[0] << '\n'; // Prints identical memory address
    //[] is a postfix operator (level 2)
    //& is a unary operator, level 2 R -> L

    int* ptr{ prime }; // Implicit array decay: int[5] decays to int*
    std::cout << *ptr << '\n';      // Prints 2

    //sizeof doesn't decay a c style array 
    //& doesn't decay 
}