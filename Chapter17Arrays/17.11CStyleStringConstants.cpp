const char name[]{ "Alex" };

//String literal "Alex" is stored in read-only memory. all string literals are stored in read only memory 
//the data is copied from .ro to stack at runtime 
//the variable name itself is stored in on the stack 
//ineffeinct as the data is copied from .ro to stack, despite the fact that the name is const and wont change

const char* const color{"Orange"};
//literal "Orange" is placed in read only memory 
//color variable is on the stack, stores a pointer to the literal in .ro memory, this is good 

//String pooling 

const char* name1{ "Alex" };
const char* name2{ "Alex" };

//uses the same string literal for both strings in .ro memoruy 

//Type Deduction 

auto s1{ "Alex" };  // Deduced as: const char* (decays to pointer)
auto* s2{ "Alex" }; // Deduced as: const char*
auto& s3{ "Alex" }; // Deduced as: const char(&)[5] (binds reference to array, length preserved!)
//normall arrays decay to pointers, reference binds to arrrays 


#include <iostream>

int main() {
    char c{ 'Q' };
    std::cout << &c << '\n'; // DANGER: Prints 'Q' followed by garbage, then crashes!
    //because pure char just has Q, no null terminator, so cout just keeps printing and printiing 
}