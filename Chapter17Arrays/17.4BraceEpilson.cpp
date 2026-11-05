#include <array>
#include <iostream>


struct House {
    int number{};
    int stories{};
    int roomsPerStory{};
};
//This above struct is built perfectly fine 



//assume std::array looks like 
//std::array is just a wrapper for the c-style array 
struct array2 {
    int arr[5];
}

//The first {} is for the std::array 
//We assume the second {} is for 1st member variable (arr)
//Assums the third {} is for the third member variable, doesn't compile 
std::array<House, 2> houses {
    { 13, 1, 7 },
    { 14, 2, 5 }
}; 

std::array<House, 2> houses {{
    { 13, 1, 7 },
    { 14, 2, 5 }
}}; 

//The second braces does the trick, moves into the first member variables and fills it up 

//Or just make it clear that we are building houses 
constexpr std::array houses {
    House{ 13, 1, 7 },
    House{ 14, 2, 5 },
    House{ 15, 2, 4 }
};


int main () {
    std::cout << "" << std::endl;

}