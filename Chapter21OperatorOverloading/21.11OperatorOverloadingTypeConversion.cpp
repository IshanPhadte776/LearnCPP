#include <iostream>

class Cents {
private:
    int m_cents{};

public:
    explicit Cents(int cents) : m_cents{ cents } {}

    // Overloaded typecast to int:
    operator int () const {
        return m_cents;
    }
};

void printInt(int val) {
    std::cout << val << '\n';
}

int main() {
    Cents cents{ 50 };

    // Implicit conversion from Cents to int:
    printInt(cents); // Prints 50

    // Explicit conversion via static_cast:
    int value{ static_cast<int>(cents) };
}