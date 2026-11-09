#include <iostream>

class Base {
public:
    ~Base() { // Non-virtual destructor
        std::cout << "Calling ~Base()\n";
    }
};

class Derived : public Base {
private:
    int* m_array{};

public:
    Derived(int length) : m_array{ new int[length] } {}

    ~Derived() {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main() {
    Derived* derived{ new Derived(5) };
    Base* base{ derived };

    delete base; // DANGER: undefined behavior / resource leak

    return 0;
}

//Because the Base's destructor is not marked as virtual, we rely on static binding for destructor for Base, 
//Because the dervied object is in a Base* object, we only call the destructor for the Base, not the destructor for the derived class


//Solution - Virtual Destructor 

class Base {
public:
    virtual ~Base() = default; // Virtual destructor
};

//under the hood, when we call delete base, program looks at the vtable
//We find the derived class destructor, then call that, then the base class destructor // this is called dynamic dispatch