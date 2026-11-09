#include <iostream>

void runTask() {
    throw 42; // Could throw anything: int, double, custom class, etc.
}

int main() {
    try {
        runTask();
    }
    catch (double d) {
        std::cerr << "Caught double: " << d << '\n';
    }
    // catch all statement 
    //msut be the last catch statement in the order 
    catch(...) { // Catch-all handler
        std::cerr << "Caught an unexpected exception of unknown type!\n";
    }

    std::cout << "Continuing normal execution...\n";
    return 0;
}