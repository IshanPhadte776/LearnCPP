//Have the define the operator overloading outside the class in-order to prevent the left-hand side (LHS) asymmetry problem 
//if defined within the class, Cents operator+ () only works when the object is on the left hand side 
//object + 5 -> object.operator+(5) -> works
//5 + object  -> 5.operator+(object )won't work, can't just define it twice 

//For non member function...
//object + 5 -> operator+(object,5) -> works 
// 5 + object -> operator+(5,object) -> works

//This works when there are getter methods for the member functions so we have access to the private variable, which can be an issue 

#include <iostream>

class Cents {
private:
    int m_cents{};
public:
    Cents(int cents) : m_cents{ cents } {}

    int getCents() const { return m_cents; } // Public accessor
};

Cents operator+(const Cents& c1, const Cents& c2) {
    return Cents{c1.getCents() + c2.getCents()};
}

int main() {
Cents cents1{ 6 };
    Cents cents2{ 8 };
    Cents centsSum{ cents1 + cents2 };

    std::cout << "I have " << centsSum.getCents() << " cents.\n"; // 14 cents

}