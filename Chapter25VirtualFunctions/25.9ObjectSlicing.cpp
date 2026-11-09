// Object Slicing when a derived object is placed in base class object by value, the derived portion of the derived class is sliced off

#include <iostream>

class Base {
protected:
    int m_value{};

public:
    Base(int value) : m_value{ value } {}
    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived : public Base {
public:
    Derived(int value) : Base{ value } {}
    const char* getName() const override { return "Derived"; }
};

int main() {
    Derived derived{ 5 };
    
    // Pass/assign by value -> SLICING OCCURS
    Base base{ derived }; 

    std::cout << base.getName() << '\n'; // Prints: "Base" (NOT "Derived"!)

    return 0;
}

//In memory, a derived object has 2 portions. The Derived portion, and the base portion 

//virtual functions don't help, cause the vptr is cut off, can't access function overriding 

//Common reasons of object slicing 

//using pass by value 
//solution is to pass by reference

Base base{derived};

// BAD: Takes Base by value -> slices any passed Derived object
void printName(Base b) { 
    std::cout << b.getName() << '\n'; 
}

// GOOD: Takes Base by reference -> preserves full dynamic object
void printName(const Base& b) { 
    std::cout << b.getName() << '\n'; 
}

#include <vector>

//Another reason for object slicing is using containers 

//this will incur object slicing as the derived portion of the derived class is cut off 
//solution is to use unqieu ptr wrappers
std::vector<Base> vec = {derived}

//When we wrap the Base class w/ unique ptr, t=object slicing doesn't happen
std::vector<unique_ptr<Base>> vec2 = {std::make_unique<Base>(5)};