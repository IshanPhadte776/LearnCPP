//Derived classes can add new member functions and new member functions for the derived classes 


#include <iostream>

class Base {
protected:
    int m_value{};

public:
    Base(int value) : m_value{ value } {}

    void identify() const {
        std::cout << "I am a Base with value: " << m_value << '\n';
    }
};

class Derived : public Base {
public:
    // Forward constructor arguments to Base
    Derived(int value) : Base{ value } {}

    // NEW FUNCTIONALITY: Only exists in Derived
    int getValue() const { return m_value; }
};

int main() {
    Base base{ 5 };
    base.identify(); // OK: member of Base
    // base.getValue(); // COMPILE ERROR: Base has no member named getValue

    Derived derived{ 7 };
    derived.identify(); // OK: inherited from Base
    std::cout << "Value via derived method: " << derived.getValue() << '\n'; // OK

    return 0;
}

//Member Lookup 

//when derived.someFunction() is called, complier must figure out what this binds to 

//1. Dervied Scope Check -> checks for the function call here, if yes, binds here 
//2. Upward traversal -> Checks for the function call in the upper classes in reverse order A -> B -> C.  Checks C -> B -> A, then binds
//3. If it doesn't find a resolution, error is thrown 

//this allows for overriding in the derived class

// Polymorphic Overriding is different than Name Shadowing / Redefining 

//Name Shadowing / Redefining
//done at compile time 

class Base {
public:
    void print() { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    // SHADOWS Base::print (not virtual)
    void print() { std::cout << "Derived\n"; } 
};

Derived d;
d.print(); // Prints: "Derived" (Derived scope checked first)

Base* ptr = &d;
ptr->print(); // Prints: "Base" (Static type is Base*, so it calls Base::print!)

//In this case, the derived class and the base class have functions w/ the same name, return type and parameters 
//When we create an object of the derived class. the complier miust bind the function call to 1 function. it finds a match in the derived class, then binds. it ignores the base class,  the base class version is being hidden / shadowed 

// Function Overriding 

//Runtime replacement of a function call at runtime 

class Base {
public:
    virtual void print() { std::cout << "Base\n"; } //visual is needed
};

class Derived : public Base {
public:
    // OVERRIDES Base::print
    void print() override { std::cout << "Derived\n"; } 
};

Derived d;
d.print(); // Prints: "Derived"

Base* ptr = &d;
ptr->print(); // Prints: "Derived" (Runtime dispatch finds the real object!)