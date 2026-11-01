
//When a variable from an inner block shares the name identifier name as the variable from the outer block 

#include <iostream>

int main () {
    int apples = 5;

    {
        std::cout << apples << '\n'; // 5

        int apples {0}; //local is 0
        apples = 10; //local is 0 

        std::cout << apples << '\n';  //10

    }
    std::cout << apples << '\n'; //base is still 5
    return 0;
}

//Tips and Tricks 

//Don't even do variable shadowing, just causes bugs and hard to trace 
// global variables of g_fe prevent this 
//-Wshadow flags these issues 