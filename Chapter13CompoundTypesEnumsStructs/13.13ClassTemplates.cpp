//Problem,. can't overload for multiple types 
#include <iostream>


struct Pair {
    int first{};
    int second{};
};

template <typename T>
struct Pair {
    T first{};
    T second{};
}


int main () {
    std::cout << "" << std::endl;

}

//can't make a pair struct for double, deosn't work. Class templates are the way 