//Pointers and References of Deprived Classes from Base Classes is the start of runtime polymorphism 

#include <iostream>
#include <string_view>

class Base {
public:
    std::string_view getName() const { return "Base"; }
};

class Derived : public Base {
public:
    std::string_view getName() const { return "Derived"; }
};

int main () {
    Derived d{};
    //The derived class is a base class object, so those derived class pointers / objects can be stored in base class boxes 
    //Reference to a Derived object via a Base Reference
    Base& rBase{d};
    // Pointer to a Derived object via Base Pointer 
    Base* pBase{&d};

    std::cout << "derived is a: " << d.getName() << '\n'; // "Derived"
    std::cout << "rBase is a:   " << rBase.getName()   << '\n'; // "Base" //??
    std::cout << "pBase is a:   " << pBase->getName()  << '\n'; // "Base" //??


//Memory Layout of Derived object:
// +------------------------------------+ <--- &derived, pBase, rBase
// | Base Subobject                     |
// |   - Base members / functions       |
// +------------------------------------+
// | Derived Subobject                  |
// |   - Derived members / functions    |
// +------------------------------------+

//When we call rBase.getName / pBase.getName(), the complier looks at it via the static type Base* / Base&
//because the method is non virtual, we resolve the binding at compile time, we bind to the base class call

//use case, have function that accept the base class as a pointer / reference, pass any object (base / derived), and call methods for the base class and it works 
//flexibility for the future 

//Before

void report(const Cat& cat) {
    std::cout << cat.getName() << " says " << cat.speak() << '\n';
}

void report(const Dog& dog) {
    std::cout << dog.getName() << " says " << dog.speak() << '\n';
}
// Adding 20 more animals requires writing 20 identical functions!

// // One function handles Cat, Dog, or any future animal derived from Animal:
void report(const Animal& animal) {
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

}