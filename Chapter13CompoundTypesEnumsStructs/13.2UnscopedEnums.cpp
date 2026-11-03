#include <iostream>

enum Color {
    red, 
    green,
    blue,
};

enum Feeling{
    tired,
    hungry,
    //blue, // enums will lead this to an error, blue is already defined in color enum
    //blue polluates the global namespace 
    //enums are known as "unscoped" because the values for the enums pollate the global namespace
};




int main () {
    std::cout << "" << std::endl;

    Color c{red}; //instantiate an enum variable of type Color and assign it to value red 
    Color c{Color::red}; //this also works, but the :: is not required for unscoped enums

    return 0;

}