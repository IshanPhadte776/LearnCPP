Dynamic casting allows for pointers / references of a base class into a derived class at runtime 
this is called downcasting 

//The need for downcasting is for a pointer / reference to the base class to call methods that are exclusive to the derived class 

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void derivedOnlyFunction() { std::cout << "Derived special logic!\n"; }
};

//base -> derivedOnlyFunction() doesn't work because the base class has no knowledge of the derived class 
//virtual functions don't help, can't override something that doesn't exist at the base class level 

//static_cast allows for conversions at compile time, but lacks run time verification 

// Base b;
// Base* bPtr = &b; // Actually points to a Base object!

// // Compiles, but UNDEFINED BEHAVIOR:
// Derived* dPtr = static_cast<Derived*>(bPtr); 
// dPtr->derivedOnlyFunction(); // Accesses unallocated memory / garbage

//static cast works well fopr fundamental types, not for user definied base / derived classes, doesn't do the allocation of derived objects 

//Solution - Dynamic Cast w/ Pointers 

//dynamic cast does RTTI (Run time type information) 
//if the cast is invalid, a nullptr is returned 

#include <iostream>

class Base {
public:
    virtual ~Base() = default; // Makes Base polymorphic
};

class Derived : public Base {
public:
    void doDerivedWork() { std::cout << "Working in Derived!\n"; }
};

void process(Base* b) {
    // Attempt the downcast:
    Derived* d = dynamic_cast<Derived*>(b);

    if (d) { // nullptr check verifies success
        d->doDerivedWork();
    } else {
        std::cout << "Object is not an instance of Derived.\n";
    }
}

int main() {
    Derived d;
    Base b;

    process(&d); // Cast succeeds -> "Working in Derived!"
    process(&b); // Cast fails safely -> "Object is not an instance of Derived."
}

//we can't type cast base classes to instances of the derived classes (by value, doesn't work)
//We can only type cast Base* / Base& -> Derived* / Derived& if and only if the object is an instance of the derived class

//Dynamic Casting can be seen as an alternative to virtual functions, can lead to designs like this 

// AVOID: Re-inventing manual dispatch
if (auto* cat = dynamic_cast<Cat*>(animal)) {
    cat->meow();
} else if (auto* dog = dynamic_cast<Dog*>(animal)) {
    dog->bark();
}

//instead, just use a virtual function in the base animal class and override it in all dogs and cat classes 

//Dynamic cast is extremely expensive, must go through hierachy and rtti at runtime, wasting cpu clock cycles 