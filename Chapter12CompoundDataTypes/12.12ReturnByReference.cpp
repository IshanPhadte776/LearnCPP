//Return by Reference, returning an alias to an existing variable, not a copy of the variable
//we dont want return by value, thats going to cause a copy, bad 
#include <iostream>
#include <string>

const std::string& getProgramName() {
    static const std::string s_name{ "Calculator v1.0" };
    return s_name; // Returns a reference to s_name — no copy is made!
    //this is fine because s_name is static, it will live for the lifetime of the program, so returning a reference to it is safe. If s_name were a local variable (non-static), returning a reference to it would be dangerous because it would go out of scope and be destroyed when the function returns, leading to undefined behavior.
}

int main() {
    std::cout << "Running: " << getProgramName() << '\n';
}

//Can't return local varaibles by refernece, the address is cooked after the blokc is over 