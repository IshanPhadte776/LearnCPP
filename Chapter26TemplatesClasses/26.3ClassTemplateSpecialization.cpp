#include <iostream>

//Speclaization for class templates for specific types 
//The specialization doesn't inherit anything from the primary template, gotta redefine everything 
// 1. Primary (generic) class template
template <typename T>
class Storage {
private:
    T m_value{};

public:
    Storage(T value) : m_value{ value } {}

    void print() const {
        std::cout << m_value << '\n';
    }
};

// 2. Full class template specialization for double
template <>
class Storage<double> {
private:
    double m_value{};

public:
    Storage(double value) : m_value{ value } {}

    // Customized formatting for doubles
    void print() const {
        std::cout << std::scientific << m_value << '\n';
    }
};

int main() {
    Storage<int> nValue{ 5 };
    Storage<double> dValue{ 6.7 };

    nValue.print(); // Uses generic template: prints 5
    dValue.print(); // Uses specialization: prints 6.700000e+00
}

template <typename T>
class Storage {
private:
    T m_value{};

public:
    Storage(T value) : m_value{ value } {}
    void print() const { std::cout << m_value << '\n'; }
};

// Specialize ONLY the print() member function for double:
template <>
void Storage<double>::print() const {
    std::cout << std::scientific << m_value << '\n';
}

//Running specialization for just 1 function is fine too, that works 