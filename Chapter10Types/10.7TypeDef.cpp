#include <iostream>

//Leads to zero runtime overhead 
//Modern, Idiomatic 
//type alias ahear to scope rules
using DDouble = Double;

//typedef is the old version 
typedef double DDDouble;

int main () {
    std::cout << "" << std::endl;

    DDouble g = 4.0;

    DDDouble h = 4.5;

}

//Why using > typedef 
//REadablility using the = operator

//Type alias aren't type safe, not new types, just different names for the same underlying data type 

using Miles = long;
using Speed = long;

Miles distance{ 5 };
Speed clockRate{ 3200 };

distance = clockRate; // Compiles cleanly without warnings!