#include <cstarg> 
#include <iostream>

//Ellipsis (...) allows a functions to accept n, n+1, n+2 parameters 

//this works 
//the ellipsis must be the last parameter 
int func(int count, ...) {

    int sum {0};

    //pointer like handle to handle the sequence of ellipsis arguments
    std::va_list list;

    //starts the va_list to count variable, next is the first ... parameter
    va_start(list, count);

    for (int i {0}; i < count; ++i) {
        //pulls out the type and the variable, and increments the pointer
        //Very dangerous because of this typing stuff, not type safe
        //no metadata about length so its unsafe in that regards 
        sum += va_arg(list, int);
    }

    va_end(list); //cleanup

    //just pass a vector or a struct for args 
    //use std::span 
    //use std::initialization_list<type>

    //C++ 17 Fold expression works too 
// template <typename... Args>
// auto sum(Args... args) {
//     return (... + args); // C++17 fold expression
// }



}