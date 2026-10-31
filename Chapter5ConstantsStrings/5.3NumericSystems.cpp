#include <iostream>
#include <bitset> 
#include <print>

int main () {
    int oct = {012}; //octal representation of 10, not 12
    int hex = {0x12}; //hexadecimal representation of 18, not 12
    int bin = {0b1100}; //binary representation of 12, not 1100



    std::cout << oct << std::endl;
    std::cout << hex << std::endl;
    std::cout << bin << std::endl;

    //std::bitset allows us to print in binary 
    std::cout << std::bitset<8>(oct) << std::endl; //prints 00001010

    //Problem with std::cout is that you there's so amny << << operators, its tiresome to work with
    //printf is type unsafe
    //std::print is type safe
    //C++ 23 addition
    std::println("Oct variable is {}, Hex variable is {}, Bin variable is {}", oct, hex, bin);

}