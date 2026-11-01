//There's C style std::rand() (outdated)
//There's also <random>

//seeding via std::random_device{} is best 

#include <random>
#include <iostream>

int main (){
    std::mt19937 mt {std::random_device{}()};

    //makes a fair die 
    std::uniform_int_distribution die{1,6};

    std::cout << die(mt) << std::endl;
}