#include <iostream>

class Accumulator {
private:
    int m_value{ 0 };

public:
    void add(int value) { m_value += value; }

    // Declare a non-member friend function
    friend void print(const Accumulator& accumulator);
};

// print() is a normal, non-member function (no Accumulator:: prefix)
void print(const Accumulator& accumulator) {
    // Has direct access to private member m_value!
    std::cout << "Accumulator value: " << accumulator.m_value << '\n';
}

int main() {
    Accumulator acc{};
    acc.add(10);
    print(acc); // Called like a normal function: print(acc), NOT acc.print()
    return 0;
}


// /Friend functions are functions defined outside of the class, but has access to the private member variables, 



#include <iostream>

class Storage {
private:
    int m_nValue{};
    double m_dValue{};

public:
    Storage(int nValue, double dValue)
        : m_nValue{ nValue }, m_dValue{ dValue } {}

    // Grant StorageDisplay full access to Storage's private members
    friend class StorageDisplay;
};

class StorageDisplay {
public:
    void print(const Storage& storage) {
        // Direct access to m_nValue and m_dValue
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    }
};

//Classes can exist in other classes as friends, allowing access to private member variables within the class itself 

//Friendship is not mutual / symmetrical

//Friendship is not transtive A -> B -> C    A isn;'t 100% friends with C
//Friendship is not inherited 