// std::vector<bool> stores 8 boolean in a byte, instead of 1 bool ina byte
//bit packing is used for the technique 

//use a std::bitset if we want to store a container of bits / bool

#include <iostream>
#include <vector>

int main() {
    std::vector<bool> v{ true, false, true };

    //we expect this to return a bool&
    //no, we get a std::vector<bool>::reference object 
    auto boooo = v[0];

    //this modifies through the proxy 
    v[0] = true;

    return 0;
}