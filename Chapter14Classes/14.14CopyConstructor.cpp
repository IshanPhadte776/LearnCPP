#include <iostream>

class Fraction {
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {

    // Explicit Copy Constructor
    //copy constructor must use a reference, not pass by value
    //pass by value requires a making a copy, which reciurive reuquires a copy, ... infinite loop, bad 
    Fraction(const Fraction& other)
        : m_numerator{ other.m_numerator }
        , m_denominator{ other.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }
    }

    void print() const {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    
};

//this calls the copy consturctor as we are passing by value 
void print (Fraction f) {

}

// this disables copying and th ecopy consutrctors 
//Fraction(const Fraction& other) = default;

int main() {
    //
    Fraction f{3,5};
    //Copy initilization, calls the copy constuctors
    Fraction fCopy{f};


}