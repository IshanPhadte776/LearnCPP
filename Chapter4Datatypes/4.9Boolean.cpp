//booleans store either true or flase, internally, 1 = true, 0 = false. therefore, bool is a integral type

#include <iostream>

int main () {

    bool isTrue = true;
    bool b;
    
    //prints 1, not true, because internally, 1 = true, 0 = false
    std::cout << isTrue << std::endl;

    //sending std::boolalpha to std::cout will make it print true / false instead of 1 / 0
    std::cout << std::boolalpha; //sets the std::cout to print true
    std::cout << isTrue << std::endl; //prints true

    std::cin >> std::boolalpha;
    std::cin >> b;
}