//static keyword has dual meaniong, depending on if the variable is for a global variable or a block variable 

//for global variable, it affects linkage, changes to internal linkage. the variable is only accessible to this translation unit 

//for local variables, it changes its storage duration. Changes from automatic duration to static storage 

//static local variables, data is stored in the .data section, but visibilty only in that block

#include <iostream>

void incrementAndPrint() {
    static int s_value{ 1 }; // Initialized only once
    ++s_value;
    std::cout << s_value << '\n';
} // s_value goes out of scope, but is NOT destroyed

int main() {
    incrementAndPrint(); // prints 2
    incrementAndPrint(); // prints 3
    incrementAndPrint(); // prints 4
    return 0;
}

//Good for creating IDs, 1,2,3,4,