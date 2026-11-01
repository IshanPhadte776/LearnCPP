//function calls lead to a lot of overhead
//CPU registers must be preserved, arguments and data must be added and removed from the stack s
//cpu branchs to the functions machine code address (cache misses can occur)

//for big functions, its fine for modular code, for smaller functions, its a different story.

//for small functions, the function overhead might be too expensive 


//Solution - inline expansion - replacing a function call directly with the body of the function 


int min(int x, int y) {return (x < y) ? x : y;}

int main () {
    int a {min(5,6)};
}

//Odd C++, required the inline keyword, nowadays, the compliers handles this on its own. will inline only when needed, will ignore inline if its a waste


//inline variables 
//has external linkage by default 
// can be defined in multiple translation untis with causing ODR issues 

//linkers ensures all translation units have the same address and instance 

// constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
    inline constexpr double pi { 3.14159 };
    inline constexpr double gravity { 9.8 };
}

#endif