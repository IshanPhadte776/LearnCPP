// max.h
#ifndef MAX_H
#define MAX_H

template <typename T>
T max(T x, T y); // Forward declaration of template

#endif

// max.cpp
#include "max.h"

template <typename T>
T max(T x, T y) { // Template definition
    return (x < y) ? y : x;
}

// main.cpp
#include "max.h"
#include <iostream>

int main() {
    std::cout << max(3, 5) << '\n'; // Wants max<int>(int, int)
    return 0;
}

//This doesn't work, main.cpp gets the .h code copy and pasted in their translation unit, just the template blueprint, when it calls max(int,int), it doesn't create the function instantiation, it expects the other translation unit to have the <int> instantation 
//The other translation unit, max.cpp just has the definition, not the int definition, that's made dynamically, but can't be made at linking. so this fails 

//solution is that max.h needs the function declaration and definition. 