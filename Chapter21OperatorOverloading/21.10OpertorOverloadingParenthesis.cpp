#include <iostream>

class Accumulator {
private:
    int m_counter{ 0 };

public:
    // Overloaded function call operator
    int operator()(int i) {
        return (m_counter += i);
    }
};

int main() {
    Accumulator acc{};
    //overloading the object() operator 

    std::cout << acc(10) << '\n'; // Prints 10
    std::cout << acc(20) << '\n'; // Prints 30
}

