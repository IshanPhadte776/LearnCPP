//CTAD = Class Template Argument Deduction 
//How the compiler deduces the types for the template at compile time 
//prior to C++17, types had to be passed at compile time for template parameters 
//If we are doing type deduction, there needs to be a clear best option 


template <typename T, typename U>
struct Pair {
    T first{};
    U second{};
};

template <typename T>
stuct SinglePair {
    T first {};
    T second {};
};

std::pair<int,double> p1 {1,2.3};

std::pair p2 {1,4.5};

Pair p3 {}; //compile error, no way to deduce the types 

SinglePair p4 {4,5.4}; // ambigious call

//CTAD works for object definition


void print(Pair p); // doesn't work 

template <typename T, typename U>
void print(Pair<T,U> p);
