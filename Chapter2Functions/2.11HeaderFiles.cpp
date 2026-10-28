//Header files ae used for forward declaration, logically seperation, and so there's less repeating of forward declarations if multiple cpp files use the same functions

//Header files include header guards (ifdef, ifndef), forward function declarations, class prototypes
//Header files shouldn't include definitions for functions, just declarations, dont want to disrupt ODR

//only #include "file.h", never #include "file.cpp", will violate ODR because we will copy and paste the CPP file in the other CPP file

// #include "file.cpp" == looks within the folder first, then toolchain. 
// #include <file> == looks at the toolchain directly 

//.c files = treats like c code, won't allow cpp libraries / conventions, uses c complier frontend 

//..cpp = treats like c++ code, enables C++ libraries, uses c++ complier frontend 

//.h / .hpp are somewhat interchangable
//.h == just use this for forward declarations, if you put your headers in a .cpp file, the complier will put all cpp files in different .o files. 
//2 cpp file = 2 .o 1 cpp file + .h file = 1 .o
//Issues (ODR) happens when the same function has definitons in 2 object files .o, many forward declarations is fine.

//utils.cpp (should be utils.h)
    // int getNumber() {
    //     return 42;
    // }


//main.cpp
    // #include <iostream>
    // #include "utils.cpp" // You include it like a header

    // int main() {
    //     std::cout << getNumber() << '\n';
    //     return 0;
    // }

//This creates 2 object file, main.o and utils.o  Both have a definition for getNumber{}, ODR
//If utils.h, this is 1 translation unit w/ 1 .o file, no ODR error