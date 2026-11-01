// External Linkage, variavles can be seen and access in this and other translation units 

//functions are external linkage by default 
//non const global variables 
// extern variables 

// a.cpp (Definition)
int g_x { 2 }; // Non-const global: defines g_x with external linkage

// main.cpp (Forward declaration & usage)
#include <iostream>

extern int g_x; // Forward declaration: tells compiler g_x is defined in another file

int main() {
    std::cout << g_x << '\n'; // Prints 2
    return 0;
}



//for const variables, we need the double extern for both sides, the producer and consumer 
// constants.cpp
extern const int g_y { 42 }; // Definition with external linkage

// main.cpp
#include <iostream>

extern const int g_y; // Forward declaration

int main() {
    std::cout << g_y << '\n'; // Works: prints 42
    return 0;
}