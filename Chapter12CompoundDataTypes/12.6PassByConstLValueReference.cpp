#include <iostream>

//Universal parameter binding 

//function parameters that wants a  const lvalue reference can accept both lvalues and rvalues and const / non cost 
//const T& takes everything 



void printRef(const int& value){
    std::cout << "value: " << value << std::endl;
}


int main() {
    int x {5};
    const int y {10};

    printRef(x); //x is an LValue, can be passed by const lvalue reference
    printRef(y); //y is an LValue, can be passed by const lvalue
    printRef(20); //20 is an RValue, can be passed by const lvalue reference // creates a temp copy of 20 and passes it to the function, lifetime of the temp copy is extended to the lifetime of the const lvalue reference

    //pass by value for small types
    //pass by reference for large types

    //std::string_view > const std::string&
}