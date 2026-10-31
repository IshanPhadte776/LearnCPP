
//passing an std::String is expensive 
//requires making a copy, makes heap allocation, just for something that might need require it. 

//Solution - std::string_view (C++ 17)
//provides a read-only access to a pre-built string w/o copying
// Lightweight, provides a pointer to the first char in a string and length variable

#include <iostream>
#include <string_view>

void printSV (std::string_view strstr) { // cheap, pass by value 
    //can handle passing in a c style string const char* and std::string and std::String_view
    std::cout << strstr;

}



int main () {
    std::string_view sv = {"Hello"};
    printSV(sv)

    std::string name = "John";
    std::string_view sv{name};

    sv = "John2";

    //sv will now read "John2"
    //name is still John

    //sv is th postfix 
    std::string_view = "Sonic"sv;

    //because std::string_view doesn't require heap allocations, they can be constexpr
    
    constexpr std::string_view sv2 = "Knuckles";

}


// converting back string_view -> string leads to complier issue 

