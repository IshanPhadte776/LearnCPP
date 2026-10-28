
#include <iostream>

//Command to run is g++ std=c++23 main.cpp -o main
//don't use gcc, it calls the linker in c mode, not c++ mode, which might not link c++ libraries (like std:: correctly)

//gcc for c, g++ for c++

int main () {
    std::cout << "Hello World" << std::endl;
    return 0;
}

//Q1. Statement = Instructions for a program to do something, typically requires a ; to finish the line 

//Q2. Function = callable block of code. which calls statements sequentially 

//Q3. name of the function all c++ programs must have int main() {}

//Q4. What happens when the program is run = statements in the main function execute 

//Q5. statements end with a ; in c++

//Q6. Syntax Error = When the program doesn't comply with the grammer of the language 

//Q7.  What is the C++ Standard Library = Precomplied code that can be reused in other programs. 
// for #include <vector> ...
//Step 1. Preprocessor will copy paste the declartion files (header files) from the toolchain (thats local) to the application source code
//Step 2. Compile, Turns the source code into machine code, but leaves blanks / sockets for the external libraries like std::cout 
//Step 3. Links the main.o object file and libc++.dylib(so) together. 


//algorithm.cpp   ──► algorithm.o ──┐
//chrono.cpp      ──► chrono.o    ──┤
//iostream.cpp    ──► iostream.o  ──┼──► Linker (ld) ──► libc++.dylib(so) (Unified shared binary)
//locale.cpp      ──► locale.o    ──┤
//thread.cpp      ──► thread.o    ──┘

//All of std is in the libc++.so binary 

