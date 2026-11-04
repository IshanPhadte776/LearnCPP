#include <iostream>

class Fraction {
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};

class Foo {
public:
    Foo () { // this is generated automatically=, assuming ni other constructor is created 
        std::cout << "Foo constructed" << std::endl;
    }

    // Foo() = default for default initialization 

    Foo (int var){
        std::cout << var << std::endl;
    }

    void print const () {
        std::cout << "print" << std::endl;
    }
};

int main() {
    // Fraction f{ 5, 2 }; // COMPILE ERROR: Cannot access private members via aggregate init
    Foo f{};
    Foo f{5};
}

//This code doesn't compile because when we mark the member variables are private for encapulation, we can't set then at initilizationn of the object , constructors fix this issues

