//For function overriding, it can be quite fragile , we don't want silent failures 
//tldr - dev mistake where the virtual override isn't 1 for 1 the same as the base class 

class Base {
public:
    virtual std::string_view getName1(int x) const { return "Base"; }
    virtual std::string_view getName2(int x) const { return "Base"; }
    virtual std::string_view getName3(int x) const { return "Base"; }
};

class Derived : public Base {
public:
    // Bug 1: Parameter type mismatch (short vs int)
    virtual std::string_view getName1(short x) const { return "Derived"; }

    // Bug 2: Missing const qualifier
    virtual std::string_view getName2(int x) { return "Derived"; }

    // Bug 3: Typo in function name
    virtual std::string_view getname3(int x) const { return "Derived"; }
};

//Solution - override keyword for the derived class's implementation class 

class Derived : public Base {
public:
    // COMPILE ERROR: Derived::getName1(short) does not override Base::getName1(int)
    std::string_view getName1(short x) const override { return "Derived"; }

    // COMPILE ERROR: Derived::getName2(int) is not const, Base is const
    std::string_view getName2(int x) override { return "Derived"; }

    // COMPILE ERROR: No function named getname3 in Base
    std::string_view getname3(int x) const override { return "Derived"; }

    // CORRECT: Exact signature match
    std::string_view getName1(int x) const override { return "Derived"; }
};

//override keyword in the derived class code turns silent error to compile error

class A {
public:
    virtual void print() { std::cout << "A"; }
};

class B : public A {
public:
    // B overrides A::print, but forbids any further subclasses from overriding print()
    void print() override final { std::cout << "B"; }
};

class C : public B {
public:
    // COMPILE ERROR: cannot override final function 'B::print'
    void print() override { std::cout << "C"; }
};

//the final keyword prevent functiomn overrides, you will get compile errors 


#include <iostream>

class Base {
public:
    virtual Base* getThis() { 
        std::cout << "called Base::getThis()\n";
        return this; 
    }
};

class Derived : public Base {
public:
    // Covariant return: returns Derived* instead of Base*
    Derived* getThis() override { 
        std::cout << "called Derived::getThis()\n";
        return this; 
    }
};

int main() {
    Derived d{};
    
    // When calling via Derived, the return type is statically known as Derived*:
    Derived* dPtr = d.getThis(); // No explicit static_cast needed!

    // Polymorphism still works through base pointers:
    Base* bPtr = &d;
    Base* result = bPtr->getThis(); // Dynamically calls Derived::getThis()
}

//Covariant -> if the base function returns a base pointer / reference, the derived class can return a derived pointer / reference