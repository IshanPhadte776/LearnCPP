

// Variable Declaration = States that a variable exists, doesn't allocate memory 
//ie extern int max;


// Variable Definition = States that a variable exists, allocates memory 
//ie int score;

// Variable Initialization = States a variable exists, allocates memory and assigns a value 
//ie. int score = 1; 


#include <iostream>

int main () {

    //Default initalization
    int i;

    //Value initialization (Traditional)
    int j{};

    //Direct initialization (Traditional)
    int k(7);

    //Copy initialization (Traditional)
    int l = 8;

    //Direct-List-initialization (Modern) (narrowing is disallowed)
    int m {4};

    //Copy-List-initialization (Modern) (narrowing is disallowed)
    int n = {5};


    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    std::cout << l << std::endl;
    std::cout << m << std::endl;
    std::cout << n << std::endl;

}

//Q1. Initialization vs Assignment 
//Initialization involves giving a value to a variable at creation, assignment gives a value at some time during the lifespan

//Q2. What form of initialization should you prefer when you want to initialize a variable with a specific value?
// Direct list initialization int v {6};

//Q3. What are default-initialization and value-initialization? What is the behavior of each? Which should you prefer?
//default has a garbage init value, value init will zero out variables in most cases