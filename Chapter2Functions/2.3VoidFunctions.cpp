#include <iostream>

int main () {
    std::cout << "" << std::endl;

}

//function with a void return still returns, it returns nothing 

//void func() {
//    return
//}

//This is still valid, but redundant but can be useful 


// #include <iostream>

// void printA()
// {
//     std::cout << "A\n";
// }

// void printB()
// {
//     std::cout << "B\n";
// }

// int main()
// {
//     printA();
//     printB();

//     return 0;
// }

//This prints A and B on different lines


// #include <iostream>

// void printA()
// {
//     std::cout << "A\n";
// }

// int main()
// {
//     std::cout << printA() << '\n';

//     return 0;
// }

//This doesn't compile, printA returns void, but void type can't be put into the std:cout, so compile error 