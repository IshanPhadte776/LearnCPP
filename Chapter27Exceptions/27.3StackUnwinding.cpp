//For exceptions that propagate though functions, if the grandchild class throws an exception, and no cathc is found there, the stack frame is unwinded and goes to the parant, grandpa until reaching the base 

#include <iostream>

void functionD() {
    std::cout << "Starting D\n";
    throw -1; // Throws an int
    std::cout << "Ending D\n"; // Skipped
}

void functionC() {
    std::cout << "Starting C\n";
    functionD();
    std::cout << "Ending C\n"; // Skipped
}

void functionB() {
    std::cout << "Starting B\n";
    functionC();
    std::cout << "Ending B\n"; // Skipped
}

void functionA() {
    std::cout << "Starting A\n";
    try {
        functionB();
    }
    catch (int x) {
        std::cerr << "Caught exception in A: " << x << '\n';
    }
    std::cout << "Ending A\n"; // Executes normally after handling
}

int main() {
    functionA();
    return 0;
}

// Output = 

// Starting A
// Starting B
// Starting C
// Starting D
// Caught exception in A: -1
// Ending A

//exception in function d -> unwinds func d -> goes to func c -> unwinds fun c- > keeps going until a 
//when unwinding, we destory the local scope variables in reverse order of constructio and call the destructors 
//This is called stack unwinding 

//pls pls pls use smart pointe wrappers for all variables or use standard containers,
//smart pointers ensure that all dynamically allocated memory will be deallocated in the case of stack unwinding  