#include <iostream>


//Type Definition
//Teaches the complier the layout of a Faction struct
//Allocates 0 bytes of memory 
struct Faction {
    int numerator{};
    int denominator{};
}; //structs must end with a semicolon


int main() {

    Faction f1; 
    f1.numerator = 1;
    f1.denominator = 2;

    std::cout << "Faction: " << f1.numerator << "/" << f1.denominator << std::endl;

}