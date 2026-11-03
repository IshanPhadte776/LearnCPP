//Pass by Address means passing the address of a variable to a function. This allows the function to modify the original variable's value. In C++, this is typically done using pointers.
//Only copies the 8 byte address of the variable, not the entire variable itself. This is more efficient for large data types, as it avoids copying the entire object.

#include <iostream>

void printByValue(std::string val) { // Copies the string
    std::cout << val << '\n';
}

void printByAddress(const std::string* ptr) { // Copies only an 8-byte address
    std::cout << *ptr << '\n';
}

int main() {
    std::string str{ "Hello, world!" };

    printByValue(str);        // Incurs full copy
    printByAddress(&str);     // Explicit address-of: cheap 8-byte pointer copy
}

//Pass by Address becaiuse we pass an address in and expect a pointer to be passed back out. The function can modify the original variable's value through the pointer. This is more efficient for large data types, as it avoids copying the entire object.
//pass by adress allows passing nullptr unlike reference 
//pointers to literals aren't allowed like references 
//reseating is allowed for pointers but not references